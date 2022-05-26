#include <iostream>
#include <stack>
/*<bits/stdc++.h> - Using it would include a lot of unnecessary stuff and increases compilation time.*/
using namespace std;

void stack_testing();


int main() {
    stack_testing();
    return 0;
}

class NodeWithMin
{
    private:

    public:
        int nData;
        int nMinimun;
        NodeWithMin(int Data, int Minimun) {
            nData = Data;
            nMinimun = Minimun;
        };
        ~NodeWithMin(){};

};

class CStackWithMinimum 
{
    private:
         stack <NodeWithMin> my_stack;
    
    public:
       

        void push1(int value)
        {
            int newMin = value;
           
            if(my_stack.empty() == true) {
                newMin = value;
            }
            else if(newMin <= my_stack.top().nMinimun) {
               newMin = value; 
            }
            else {
                newMin = my_stack.top().nMinimun;
            }
            NodeWithMin node(value, newMin);
            my_stack.push(node);
        }

        int get_min() {
            return my_stack.top().nMinimun;
        }

        void pop1() {
            return my_stack.pop();
        }
        NodeWithMin peek() {
            return my_stack.top();
        }

        int size() {
            return my_stack.size();
        }



};

void test(int result) {
    if (result) {
        cout<<"The test succeded"<<endl;
    }
    else {
        cout<<"The test failed"<<endl;
    }
}

void stack_testing() {
    int res = 1;
    CStackWithMinimum x;
    res *= (x.size() == 0);
    x.push1(4);
    x.push1(3);
    x.push1(6);
    res *= (x.get_min() == 3);
    x.push1(2);
    res *= (x.get_min() == 2);
    x.pop1();
    res *= (x.get_min() == 3);
    res *= (x.size() == 3);
    res *= (x.peek().nData == 6);
 
    test(res);
}


