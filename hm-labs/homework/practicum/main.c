// Use this file to write tests. We have started this process for you but
// there is much more than you can and should do. Writing simple tests
// and slowly making them more and more complicated as you develop
// your library is recommended.

// Compile this assignment with: gcc -g -Wall linked_hashmap_tests.c -o tests
//
// Run with: ./tests
#include <stdio.h>  // For IO operations
#include <pthread.h>
#include "linked_hashmap.h"
#include "treemap.h"

// Test normal operations on linked hashmap, including create empty linked-hashmap, put(handle
// duplicate keys), remove, get first in order, get last in order, print keys with insertion
// order, delete.
int unitTest1(int status) { // more units code style writing comments
  int passed = 0;
  printf("the insertion order of elements within this double linkedhashmap: \n");

  dLinkedHashmap_t hashmap = *create(10, 0.75f);
  // -----------------------------hash value
  put(&hashmap, 5, 33); // 5
  put(&hashmap, 1, 25); // 2
  put(&hashmap, 15, 10);  // 36
  put(&hashmap, 25, 6); // 96
  put(&hashmap, 25, 14);  // 96, duplicate key, should overwrite the former value
  put(&hashmap, 20, 15);  // 62
  put(&hashmap, 7, 11); // 9
  printHashmap(&hashmap);

  printf("the insertion order of elements after remove key 7, 20, 25, 15: \n");


  removeKey(&hashmap, 7);
  removeKey(&hashmap, 20);
  removeKey(&hashmap, 25);
  removeKey(&hashmap, 15);
  printHashmap(&hashmap);

  printf("remove all: \n");
  removeKey(&hashmap, 1);
  removeKey(&hashmap, 2); // try to remove not existing key

  removeKey(&hashmap, 5); // remove all
  removeKey(&hashmap, 5); // if still try to remove non existing key

//  printf("the last element's key: %d, value: %f \n", hashmap_getLast(&hashmap)->key,
//         hashmap_getLast(&hashmap)->value); // key:20, value: 15
//
//  printf("the first element's key: %d, value: %f \n", hashmap_getFirst(&hashmap)->key,
//         hashmap_getFirst(&hashmap)->value);  // key:5, value: 33

  printHashmap(&hashmap);

  freeHashmap(&hashmap);
  passed = 1;
  return passed;
}

int unitTest2(int status) {
  int passed = 0;
  // Test normal operations on treemap with asc order
  int keys[7] = {5, 1, 15, 25, 25, 20, 7};
  float values[7] = {33, 25, 10, 6, 14, 15, 11};
  for (int i = 0; i < 7; i++) {
    addNode(keys[i], values[i]);
  }

  printf("------------Test Order-----------\n");
  printf("the ascend order of elements within this treemap: \n");
  printTreemap(parent);

  deleteNode(5);
  deleteNode(15);
  deleteNode(25);
  printf("after deleting 5,15,25, updated ascending order: \n");
  printTreemap(parent);

  printf("delete all: \n");
  deleteNode(7);
  deleteNode(20);
  deleteNode(1);
  printTreemap(parent);

  deleteNode(1); // if still try to delete non-existing key

  passed = 1;

  return passed;
}

#define NUM_THREADS 2
float value = 13.5;
int key = 4;

void *task(void *arg) {
  value = value + 1;
  put(arg, key, value);
  return NULL;
}


int unitTest3(int status) {
  int passed = 0;
  // Test multiple threads can use linked hash map at the same time without deadlock or race conditions.
  pthread_t threadID[NUM_THREADS]; // 2

  dLinkedHashmap_t hashmap = *create(10, 0.75f);

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threadID[i], NULL, task, (void *) &hashmap);
  }

  // -----------------------------hash value
  put(&hashmap, 5, 33); // 5
  put(&hashmap, 1, 25); // 2
  put(&hashmap, 15, 10);  // 36
  put(&hashmap, 25, 6); // 96
  put(&hashmap, 25, 14);  // 96, duplicate key, should overwrite the former value
  put(&hashmap, 20, 15);  // 62
  put(&hashmap, 7, 11); // 9

  removeKey(&hashmap, 7);

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threadID[i], NULL);
  }

  printHashmap(&hashmap);

//  freeHashmap(&hashmap);
  passed = 1;
  return passed;
}

int (*unitTests[])(int) ={
    unitTest1,
    unitTest2,
//    unitTest3, // need to comment above two tests to perform test3
    NULL
};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main() {
  unsigned int testsPassed = 0;
  // List of Unit Tests to test your data structure
  int counter = 0;
  while (unitTests[counter] != NULL) {
    printf("========unitTest %d========\n", counter);
    if (1 == unitTests[counter](1)) {
      printf("passed test\n");
      testsPassed++;
    } else {
      printf("failed test, missing functionality, or incorrect test\n");
    }
    counter++;
  }

  printf("%d of %d tests passed\n", testsPassed, counter);

  return 0;
}

