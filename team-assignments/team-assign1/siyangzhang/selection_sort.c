#include <stdio.h>
#include <stdlib.h>

// swap to use pointer to avoid creating extra copy
void swap(int *p_value1, int *p_value2) {
  int temp = *p_value1;
  *p_value1 = *p_value2;
  *p_value2 = temp;
}

// each time select the min from unsorted part of array and put it at front using swap
void selectionSort(int arr[], int n) {
  int min;

  for (int i = 0; i < n - 1; i++) {
    min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(&arr[min], &arr[i]);
  }
}


void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Fisher-Yates shuffle algo, improve use random() instead of rand, which is a better random generator
void shuffle(int *array, size_t n) {
  if (n > 1) {
    for (int i = 0; i < n - 1; i++) {
      size_t j = i + random() / (RAND_MAX / (n - i) + 1);
      int t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
}

// print the randomized array first then print the sorted array 
int main() {
  int arr[100];
  for (int i = 0; i < 100; i++) {
    arr[i] = i;
  }

  shuffle(arr, 100);
  printArray(arr, 100);

  selectionSort(arr, 100);
  printArray(arr, 100);

}
