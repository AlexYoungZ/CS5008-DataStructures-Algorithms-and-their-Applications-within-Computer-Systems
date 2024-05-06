// https://docs.google.com/spreadsheets/d/1TjVT_jIGbLIOXBzJh1QJuk9RC7XbXfXp49NaSEUvj1U/edit?usp=sharing
// Compile with: gcc -g insertion.c -o insertion
// Run with: ./insertion

#include <stdio.h> // Include file for standart input/output
#include <stdlib.h>
#include <time.h> // Time functions

#define EXPERIMENT 1

void insertionSort(int array[], int n) {
  for (int i = 1; i < n; i++) {
    int val = array[i];
    int j = i;

    while (j > 0 && array[j - 1] > val) {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = val;
  }
}

void print(int array[], int n) {
  printf("insert sort: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
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
  bubblesort(dataset1, 11);
  bubblesort(dataset2, 11);
  bubblesort(dataset3, 11);
  bubblesort(dataset4, 11);
  bubblesort(dataset5, 11);
  bubblesort(dataset6, 11);

  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);

#else

  if (argc != 2) {
    printf("One argument expected: ./insertion 1000\n");
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
  insertionSort(random, size);
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