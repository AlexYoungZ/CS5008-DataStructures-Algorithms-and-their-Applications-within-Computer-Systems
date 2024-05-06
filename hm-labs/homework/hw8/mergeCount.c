#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
  int i = left;
  int j = mid;
  int k = left;
  int count = 0;

  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      count += mid - i;
    }
  }

  while (i <= mid - 1) {
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  // copy back
  for (int i = left; i < right; i++) {
    arr[i] = temp[i];
  }
  return count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
  int count = 0;
  int mid;
  if (right > left) {
    mid = left + (right - left) / 2;
    count += mergeSort(arr, temp, left, mid); // left
    count += mergeSort(arr, temp, mid + 1, right); // right
    count += merge(arr, temp, left, mid + 1, right); // merge
  }
  return count;
}

int mergeCount(int arr[], int size) {
  int *temp = (int *) malloc(sizeof(int) * size);
  return mergeSort(arr, temp, 0, size - 1);
}

int main() {
  int arr[] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 3, 2, 5, 4};

  int size = sizeof(arr) / sizeof(arr[0]);
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  int size2 = sizeof(arr2) / sizeof(arr2[0]);

  printf("mixed-up-ness score is: %d\n", mergeCount(arr, size)); // 120
  printf("mixed-up-ness score is: %d\n", mergeCount(arr1, size1)); // 0
  printf("mixed-up-ness score is: %d\n", mergeCount(arr2, size2)); // 2

  return 0;
}
