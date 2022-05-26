#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> //abs

using namespace std;

vector<int> findHowMachFrindIHave(vector<bool> arr)
{
    vector<int> temp = {};
    size_t size = arr.size();
    int counter = 1;
    for (size_t i = 0; i < size; i++)
    {
        if(arr[i + 1] == arr[i])
        {
            counter++;
        }
        else
        {
            if(arr[i] == 1)
            {
                temp.push_back(counter * -1);
            }
            else
            {
                temp.push_back(counter);
            }
            counter = 1;
        }
    }
    return temp;
}

void longSequence(vector<int> arr)
{
    int sum, size = arr.size(),contain,max_ = 0;
    for (size_t i = 0; i < size-1; i++)
    {
        sum = 0;
        contain = 0;
        for (size_t j = i; j < size-1; j++)
        {
            sum += arr[j];
            contain += abs(arr[j]);
            if(sum == 0)
            {
                max_ = max(contain,max_);
            }
        }
    }
    cout <<"maximum sequenc same number is : " <<max_;
}

int main()
{
    vector<bool> arr = {1,1,0,1,0,1,0,0,1,1};
    vector <int> result = findHowMachFrindIHave(arr);
    
    longSequence(result);
    return 0;
}