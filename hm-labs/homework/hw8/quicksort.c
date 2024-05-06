// https://docs.google.com/spreadsheets/d/1TjVT_jIGbLIOXBzJh1QJuk9RC7XbXfXp49NaSEUvj1U/edit?usp=sharing
// Compile with: gcc -g insertion.c -o insertion -std=c99 -D_POSIX_C_SOURCE=199309L
// Run with: ./insertion

#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
#include <time.h> // Time functions

#define EXPERIMENT 1

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// find pivot and swap
int partition(int array[], int l, int r) {
  int pivot = array[r];
  int i = l - 1;

  for (int j = l; j < r; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[r]);

  return i + 1;
}

void quickSort(int array[], int left, int right) {
  if (left < right) {
    int pivot = partition(array, left, right);

    quickSort(array, left, pivot - 1);
    quickSort(array, pivot + 1, right);
  }
}

void print(int array[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
#if EXPERIMENT == 0
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};

  // Sort our integer array
  quickSort(dataset1, 0,10);
  quickSort(dataset2, 0,10);
  quickSort(dataset3, 0,10);
  quickSort(dataset4, 0,10);
  quickSort(dataset5, 0,10);
  quickSort(dataset6, 0,10);

  // Print out an array
  print(dataset1, 11);
  print(dataset2, 11);
  print(dataset3, 11);
  print(dataset4, 11);
  print(dataset5, 11);
  print(dataset6, 11);

#else

  if (argc != 2) {
    printf("One argument expected: ./quick 1000\n");
    return 1;
  }

  // Convert the argument of the program into an integer
  const int size = atoi(argv[1]);
  // Generate a random seed
  time_t t;
  srand((unsigned) time(&t));
  // Allocate memory
  int *random = (int *) malloc(sizeof(int) * size);

  // Populate our test data set
  for (int i = 0; i < size; i++) {
    // Generate random values from 0 to 99
    random[i] = rand() % size;
  }

  // You can uncomment if you'd like to see the size sorted
//   printf("Before the sort: \n");
//   printIntArray(random, size);

  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Perform the sort
  quickSort(random, 0, size - 1);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time = %f seconds\n", time_taken);

  // Confirm the sort worked
//   printf("After the sort: \n");
//   printIntArray(random, size);

  // Free our random array
  free(random);

#endif

  return 0;
}