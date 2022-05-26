#include <iostream>
#include <vector>
#include<map>
#include <stack>

using namespace std;

class convertToString
{
    public:
    convertToString(int number):num(number){initDB();writeNumber();};
    void writeNumber();
    vector<string>  hendleTreeDigit(int num);
    private:
    
    void initDB();
    
    int num;

    vector<string> vec;
    map<string, vector<string>> DB;
};


int main()
{
    convertToString(1234419);

    return 0;
}

void convertToString::writeNumber()
{
    stack<vector<string>> stack;
    while(num)
    {
        stack.push(hendleTreeDigit(num %1000));
        num = num / 1000;
    }
    int size = stack.size();

    while(size)
    {
        
        for (auto i:stack.top())
        {
            cout<<i<<" ";
        }
        cout<<DB["ref"][size]<<" ";
        stack.pop();
        size--;
    }
}

void convertToString::initDB()
{
    DB["digit"] = {" ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};
    DB["towDigits"] = {" ","ten ", "eleven ", "twelve ","threteen","fourteen ","fiveteen ","sixteen ","seventeen ","eighteen ","nineteen "};
    DB["dozen"] = {"twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
    DB["ref"] = {"hundred", "","thousand", "million"};
}


vector<string> convertToString::hendleTreeDigit(int num)
{
    vector<string> vector;
    if (num / 100)
    {
        vector.push_back(DB["digit"][num / 100]);
        vector.push_back(DB["ref"][0]);
    }
    num = num %100;

    if (num/10 == 0)
    {
        vector.push_back(DB["digit"][num]);
    }
    else if (num/10 == 1)
    {
        vector.push_back(DB["towDigits"][num%10 + num/10]);
       

    }else if (num%10 == 0)
    {
        vector.push_back(DB["dozen"][num/10 - 2]);
       
    }
    else
    {
        vector.push_back(DB["dozen"][num/10-2] +DB["digit"][num%10]);
    }
    
    
    return vector;
    
}