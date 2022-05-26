#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <map>
#include <array>

#include<algorithm> //max
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5 
#define BufferSize 5 

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;


std::string gen_random(const int len) 
{
    static const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string tmp_s;
    tmp_s.reserve(len);
    for (int i = 0; i < len; ++i) 
    {
        tmp_s += alpha[rand() % (sizeof(alpha) - 1)];
    }
    return tmp_s;
}

class Stock {
    public:
    Stock(std::string stock_name) 
    {
        name = stock_name;
    }
    float get_current_price() 
    {
        float change = -5 + static_cast <float> (rand()) /
                        (static_cast <float> (RAND_MAX / (10)));
        stock_price += change;
        return (stock_price - change);
    }
    std::string get_name()
    {
        return name;
    }
    private:
    std::string name;
    float stock_price = 100;
};

class StockPrice {
    public:
    StockPrice();
    StockPrice(std::string n, std::array<float, 4> pr)
    {
        name = n;
        if (pr.size() == 4) 
        {
            for (int i = 0; i < pr.size(); i++) 
            {
            prices[i] = pr[i];
            }
        }
        else 
        {
            prices[0] = pr[0];
        }
    }
    virtual ~StockPrice(){};
    std::string name;
    std::array<float, 4> prices;
};

class Recommender {
    public:
    Recommender(){};
    virtual ~Recommender(){};
    void update_price(std::string stock_name, float new_price)
    {
        int index = get_stock_index(stock_name);
        if (index != -1) {
            for (int j = 3; j > 0; j--) 
            {
                p[index].prices[j] = p[index].prices[j - 1];
            }
            p[index].prices[0] = new_price;
            std::cout<<buy_or_sell(p[index]);
        }
        else 
        {
        p.push_back(StockPrice(stock_name, {new_price, 0, 0, 0 }));
        }
    }

    // IMPLEMENT YOUR CODE HERE
    // if the stock price dropped 3 continues ticks - return "buy"
    // if the stock price raised 3 continues ticks - return "sell"
    // else return empty string.
    private:
    std::string buy_or_sell(StockPrice& SP)
    {
        std::string name = SP.name;
        std::array<float, 4> p = SP.prices;

        int dropped = 1, raised = 1;

        for (size_t index = 0; index < 3; index++)
        {
            dropped *= (p[index] > p[index+1]);
            raised *= (p[index] < p[index+1]);
        }

        if(dropped) {
            name += " buy\n";
            return name;
        }else if(raised) {
            name += " sell\n";
            return name;
        }
        else{
            return "";
        }
    }
    int get_stock_index(std::string name)
    {
        for (int i = 0; i < p.size(); i++) 
        {
            if (p[i].name == name)
            {
                return i;
            }
        }
        return -1;
    };
    std::vector<StockPrice> p;
};



class middle_data_structre 
{
    public:
    middle_data_structre(){vec.push_back(std::make_pair("null",0));};
    std::pair<std::string, float> getFromVector(int index)
    {
        return vec[index];
    }
    void updateVector(std::pair<std::string, float> elem, int index)
    {
        auto itPos = vec.begin() + index;
        vec.insert(itPos, elem);
        //vec[index] = elem;
    }
    
    private:
    std::vector<std::pair<std::string, float>> vec;

};


class StockList {
    public:
    StockList() {
        all_stocks = {};
    }
    StockList(int amount) {
        for (int i = 0; i < amount; i++) {
            all_stocks.push_back(new Stock(gen_random(4)));
        }
    }
    std::pair<std::string, float> get_stock_tick() {
        int index = rand() % all_stocks.size();
        return make_pair(all_stocks[index]->get_name(),all_stocks[index]->get_current_price());
    }
    virtual ~StockList() {
        for (std::vector<Stock*>::iterator it = all_stocks.begin();it != all_stocks.end(); ++it) {
            Stock* temp = *it;
            delete(temp);
        }
    };
    private:
    std::vector<Stock*> all_stocks;
};
void printStock(std::pair<std::string, float> x)
{
    std::cout <<"name: "<<x.first<<"\nvalu: "<<x.second<<std::endl;
}
/*-----------------------------------------consumer-------------------------------------------*/

void consumer(Recommender& stock_recommender, middle_data_structre &MDS)
{   
    std::pair<std::string, float> element;

    while(1) {
        
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        /* code*/
        //printStock(element);
        element = MDS.getFromVector(out);
        //std::cout <<"\nc - "<< (out)%BufferSize<<" next index = "<<(out+1)%BufferSize<<std::endl;
        stock_recommender.update_price(element.first,element.second);
        out = (out+1)%BufferSize;

        pthread_mutex_unlock(&mutex);

        sem_post(&empty);
        
    }
}
/*-------------------------------------producer-----------------------------------------------*/

void producer(StockList& stock_list, middle_data_structre &MDS)
{   
    std::pair<std::string, float> element;

    while(1) {
        
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        /* code*/
        element =  stock_list.get_stock_tick();
        MDS.updateVector(element, in);
        //std::cout <<"\np - "<< (in)%BufferSize<<" next index = "<<(in+1)%BufferSize<<std::endl;
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        
    }
}

/*------------------------------------------------------------------------------------*/
int main(int argc, char* argv[]) 
{
    StockList stocklist = StockList(100000);
    Recommender reco = Recommender();
    middle_data_structre MDS = middle_data_structre();

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    
    
    for (size_t i = 0; i < 10; i++)
    {
        std::thread thread_pro(producer, std::ref(stocklist),std::ref(MDS));
    
        std::thread thread_con(consumer, std::ref(reco),std::ref(MDS));

        thread_con.join();
    }
    

    
    //producer(stocklist);
    //consumer(reco);
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}