using namespace std;

template <typename T>
void printArray(T array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int Max(int array[], int size) {
   int max = array[0];

   for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
   return max;
}
int Min(int array[], int size) {
   int min = array[0];

   for (int i = 1; i < size; i++) {
    if (array[i] < min)
      min = array[i];
  }
   return min;
}
