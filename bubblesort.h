
using namespace std;

template <typename T>
void swap_ptr(T *x, T *y) {
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <typename T>
void swap_ref(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
void print_arr(T arr[], int length) {
    for(int i = 0; i < length - 1; i++ ) {
        cout <<arr[i]<<",";
    }
    cout <<arr[length - 1]<<endl;
}


template <typename T>
void  bubble_sort(T arr[], int length) {
    bool is_sorted = true;
    for(int i = 0; i < length - 1; i++ ) {
        
        for(int j = 0; j < length - i -1; j++)
            if(arr[j] > arr[j + 1]) {
                //swap_ptr(arr + j + 1, arr + j);
                swap_ptr<T>((arr + j + 1), (arr + j));
                is_sorted = false;
            }    
        if(is_sorted) {
            break;
        }    
    }
}

template <typename T>
void recurs_bubble_sort(T arr[], int length) {
    if (length == 1) {
        return;
    }
    for(int i = 0; i < length - 1; i++ ) {
        if (arr[i] > arr[i+1]) {
            swap_ref<T>(arr[i], arr[i + 1]);
        }
    }
    recurs_bubble_sort(arr, length - 1);
}


