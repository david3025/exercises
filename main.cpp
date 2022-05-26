#include <iostream>
#include "counting_sort.h"
#include "buket_sort.h"

using namespace std;
/*
#include "bubblesort.h"
#include "binary_search.h"
#include "counting_sort.h"
#include "merge_sort.h"
*/


int main() 
{ 
    /*int arr[] = {64, 34, 25, 12, 22}; 
    string arr2[] = {"Dog", "Lion", "Chiken", "Elefemt", "Mouse"};
    int n = sizeof(arr)/sizeof(arr[0]); 
    //bubble_sort<int>(arr, n);
    recurs_bubble_sort<int>(arr, n);
    print_arr<int>(arr, n);

    
    recurs_bubble_sort<string>(arr2, n);
    cout<<"Sorted array: \n"; 
    print_arr<string>(arr2, n); 
    
    cout<<recurs_binary_search<int>(arr, 0, n-1, 23);
   
    //int array[] = {4, 2, -2, -8, 3, 3, 1};
    int array[] = {4,2,5,3,1};
    int n = sizeof(array) / sizeof(array[0]);
    mergeSort(array,0,4);
    printArray(array, n); 
    int array[] = {4,8,6,2,1,9,45,23,11,10};
    int n = sizeof(array) / sizeof(array[0]);
    countSort_v2(array,n);*/
    float arr[] = {0.43, -0.45, -0.93, -0.421, 0.345, 0.591};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortMixed<float>(arr, n);

    return 0; 
} 
