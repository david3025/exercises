
/*
void merge_arr(int arr[], int l, int m, int r) {
    int left = l, right = m + 1;
    while(left < right ) {
        if (arr[left] > arr[right]) {
            swap_(&arr[left], &arr[right]);
        }
        left++;
    }
}
*/
void swap_(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge_arr_ptr(int arr[], int l, int m, int r) {
    int *left = arr + l, *right = arr + m + 1;
    while(left < right ) {
        if (*left > *right) {
            swap_(left, right);
        }
        left++;
    }
}

void mergeSort(int array[], const int l, const int r)
{
    if (l >= r)
        return; 
  
    int mid = (l + r) / 2;
    mergeSort(array, l, mid);
    mergeSort(array, mid + 1, r);
    merge_arr_ptr(array, l, mid, r);
}