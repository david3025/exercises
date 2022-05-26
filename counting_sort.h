#include <bits/stdc++.h>
#include "general.h"
void countSort(int array[], int size) {

  int max = Max(array, size);
  int min = Min(array, size);
  int range = max - min + 1;
  int output[size];
  int count[range];

  memset(count, 0, sizeof(count));

 for (int i = 0; i < size; i++) {
        count[array[i] - min]++;
  }
  for (int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i] - min] - 1] = array[i];
    count[array[i] - min]--;
  }

  // Copy 
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
  printArray(output, size);
}

/*
נגדיר: מערך א מערך מנייה
מערך ב מערך החזרה

שלב א: נעבור על המערך(המקורי)נספור ונעדכן במערך א
שלב ב: סןכמים איברים במנייה (ע"מ לאפיין מקום במקורי)
שלב ג: עוברים על מקורי ומכניסים למערך החזרה , את האיבר המקורי למיקום ערך המנניה*/

void countSort_v2(int array[], int size) {

  int max = Max(array, size);
  int count[max + 1];
  int output[size];
  
  for(int i = 0; i <= max; i++) {
    count[i] = 0;
  }
  
  for (int i = 0; i < size; i++) {
      count[array[i]]++;
  }

  for (int i = 0, j = 0; i <= max ; i++) {
    while(count[i] > 0){
      output[j++] = i;
      count[i]--;
    }
  }
  
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }

  printArray(output, size);


}
