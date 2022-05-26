using namespace std;

template <typename T>
int binary_search(T arr[], int left, int right, T val) {
    int mid;
    while (left <= right )
    {
        mid = (left + right) / 2;
        if(arr[mid] < val) {
            left = mid +1;
        }
        else if (arr[mid] > val)
        {
            right = mid -1;
        }
        else return mid;    
    }
    return -1; 
}

template <typename T>
int recurs_binary_search(T arr[], int left, int right, T val) {
    int mid = (left + right) / 2;
    if (left > right ) {
        return -1;
    }
    if(arr[mid] == val) {
        return mid;
    }
    
    if(arr[mid] < val) {
        left = mid +1;
    }
    else if (arr[mid] > val)
    {
        right = mid -1;
    }

    recurs_binary_search(arr,left,right,val);
}
