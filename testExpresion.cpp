#include <iostream>
#include <vector>
#include <string>
using namespace std;

int foo()
{
    return 4;
}

void vectorToStringSplitByDelim(const vector<string>& vec, char delim, string& s)
{
    for (vector<string>::const_iterator str_iter = vec.begin(); str_iter != vec.end(); ++str_iter)
    {
        s += (*str_iter);
        if ( str_iter + 1 != vec.end() ) {
            s += delim;
        }
    }
}
int main()
{
    vector<string> vec = {"123","ad2 r","tset4 ette"};
    string r;
    vectorToStringSplitByDelim(vec, '&', r);

    cout << r<<endl;
    
    int y,x;
    /*
    if((y = foo())!=0)
    {
        std::cout << "Variable initialization is considered an expression";
    }
    */
   x = y = 9; // (y = 9) = expression
   std::cout <<"x = "<<x<<"\ny = "<<y<<std::endl;



   std::cout <<"value1 : "<<(y = foo())<<"\ny = "<< y<<std::endl;
   std::cout <<"value2 : "<<(x = 3)<<"\nx = "<< x<<std::endl;
   
   return 0;
}