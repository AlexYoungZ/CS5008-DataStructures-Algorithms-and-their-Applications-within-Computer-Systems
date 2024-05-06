#include <stdio.h>

int scoreCount(int array[], int size) {
  int count = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (array[i] > array[j]) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int arr[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 3, 2, 5, 4};

  int size = sizeof(arr) / sizeof(arr[0]);
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);

  printf("mixed-up-ness score is: %d\n", scoreCount(arr, size)); // 120
  printf("mixed-up-ness score is: %d\n", scoreCount(arr1, size1)); // 0
  printf("mixed-up-ness score is: %d\n", scoreCount(arr2, size2)); // 2

  return 0;
}

