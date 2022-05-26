#include <iostream>
#include <vector>

using namespace std;

int maxSubarray1(vector<int> vec);
int maxSubarray2(vector<int> vec);
void initVectorRandomVal(vector<int> &empty_vector);
bool testMaxSubarray();

int main()
{
    bool result = 1;
    for (size_t i = 0; i < 100; i++)
    {
        result += testMaxSubarray();
    }
    cout <<result;
    return 0;
}

int maxSubarray1(vector<int> vec)
{
    int global_max = 0, suffix_max = 0;
    int size = vec.size();
    for (size_t i = 0; i < size; i++)
    {
        if (vec.at(i) + suffix_max > global_max)
        {
            suffix_max += vec.at(i);
            global_max = suffix_max;
        }
        else if (suffix_max + vec.at(i)> 0)
        {
            suffix_max += vec.at(i);
        }
        else
        {
            suffix_max = 0;
        }
    }
    return global_max;
}

int maxSubarray2(vector<int> vec)
{
    int global_max = 0, suffix_max = 0;
    int size = vec.size();
    for (size_t i = 0; i < size; i++)
    {
        suffix_max += vec.at(i);

        if (suffix_max > global_max)
        {
            global_max = suffix_max;
        }
        else if (suffix_max < 0)
        {
            suffix_max = 0;
        }
    }
    return global_max;
}
void initVectorRandomVal(vector<int> &empty_vector)
{
    srand(time(0));
    for(int i=0;i<20;i++)
    {
        empty_vector.push_back((rand()%20) -10);
    }
}
bool testMaxSubarray()
{
      vector<int> sub_array;
      initVectorRandomVal(sub_array);
      
      return (maxSubarray1(sub_array) == maxSubarray2(sub_array));
}

