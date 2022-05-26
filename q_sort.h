using namespace std;
#include "general.h"

void swap_(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition (int arr[], int l, int r) {
    int piv = l - 1;
    int element_piv = arr[r];
    int size = r - l + 1;

    for (int i = l; i < r; i++) {
        if(arr[i] < element_piv) {
            swap_(&arr[piv + 1], &arr[i]);
            piv++;
        }
    }
    swap_(&arr[piv + 1], &arr[r]);
    return piv + 1;
}

void QuickSort(int arr[], int l, int r)
{
    if (l >= r) {
        return;
    }
    /* pi is partitioning index, arr[p] is now
    at right place */
    int pi = Partition(arr, l, r);

    // Separately sort elements before
    // partition and after partition
    QuickSort(arr, l, pi - 1);
    QuickSort(arr, pi + 1, r);
    
}
/*
void QuickSort(int arr[], int low, int high) {
    if(low < high) {
        int piv = Partition(arr, low, high);
        QuickSort(arr, low, piv -1);
        QuickSort(arr,piv + 1, high);
    }

}*/