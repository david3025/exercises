#include <iostream>
#include <stack>
using namespace std;

void stack_testing();


int main() {
    stack_testing();
    return 0;
}


template <typename T>
class CStackWithMinimumV2 {
    private:
        stack <T> my_stack;
        int min_elem = INT8_MAX;
    public:
        void push(T element) {
            if (element > min_elem) {
                my_stack.push(element);
            }
            else{
                my_stack.push((element * 2) - min_elem);
                min_elem = element;
            }
        }
        T peek() {
            return my_stack.top();
        }
        void pop() {
            T element = my_stack.top();
            if (element > min_elem) {
                my_stack.pop();
            }
            else{
                min_elem = (min_elem * 2) - element;
                my_stack.pop();
            }
        }
        void print_stack() {
            stack <T> temp_stack;
            while(!my_stack.empty()) {
                T temp_elem = my_stack.top();
                cout << temp_elem<<",";
                my_stack.pop();
                temp_stack.push(temp_elem);
            }
            while(!temp_stack.empty()) {
                T temp_elem = temp_stack.top();
                temp_stack.pop();
                my_stack.push(temp_elem);
            }
        }
        T get_min() {
            return min_elem;
        }

        T size() {
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
    CStackWithMinimumV2 <int> x;
    res *= (x.size() == 0);
    x.push(4);
    x.push(3);
    x.push(6);
    res *= (x.get_min() == 3);
    x.push(2);
    res *= (x.get_min() == 2);
    x.pop();
    res *= (x.get_min() == 3);
    res *= (x.size() == 3);
    res *= (x.peek() == 6);
 
    test(res);
}
