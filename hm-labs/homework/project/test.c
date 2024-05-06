#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#include "ternarySearchTree.h"

// Test ternary trie insert and contain function
void unitTest1() {
  puts("Test ternary trie insert and contain function");

  tstNode_t *root = (tstNode_t *) NULL;
  // test insert and check contain
  root = insert(root, "cat");
  assert(contain(root, "cat"));

  // insert another word having cat as prefix
  insert(root, "cats");
  assert(contain(root, "cats"));
  // test not contain messy words
  assert(!contain(root, "cast"));
  assert(!contain(root, "catss"));

  // test category use cat as prefix and go left
  insert(root, "category");
  assert(contain(root, "category"));

  // test category use cat as prefix and go right and check leaf
  tstNode_t *catsNode = getNode(root, "cats");
  assert(isLeafNode(catsNode));

  tstNode_t *catNode = getNode(root, "cat");
  assert(!isLeafNode(catNode));

  insert(root, "test");
  assert(contain(root, "test"));

  puts("Pass insert and contain tests");

  deleteTST(root);
}

// Test ternary trie print function
void unitTest2() {
  puts("Test ternary trie print function");

  tstNode_t *root = (tstNode_t *) NULL;

  root = insert(root, "cat");
  assert(contain(root, "cat"));

  // insert another word having cat as prefix
  insert(root, "cats");
  assert(contain(root, "cats"));
  // test not contain messy words
  assert(!contain(root, "cast"));
  assert(!contain(root, "catss"));

  // test category use cat as prefix and go left
  insert(root, "category");
  assert(contain(root, "category"));

  // test category use cat as prefix and go right and check leaf
  tstNode_t *catsNode = getNode(root, "cats");
  assert(isLeafNode(catsNode));

  tstNode_t *catNode = getNode(root, "cat");
  assert(!isLeafNode(catNode));

  insert(root, "test");
  assert(contain(root, "test"));


  // test print ternary search tree in order
  char buffer[50];
  printTST(root, buffer, 0);

  puts("Pass print tests");

  deleteTST(root);
}

// Test auto-completion function with given word dictionary
void unitTest3() {
  puts("Test auto-completion function with given word dictionary");

  tstNode_t *root = (tstNode_t *) NULL;
  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

  root = createTSTFromFile(root, "dictionary.txt");

  assert(contain(root, "cat"));

  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time of create tst from file and find a word = %f seconds\n", time_taken);



  puts("Pass auto-completion tests using given word dictionary");

  deleteTST(root);
}

int main() {
  unitTest1();
  unitTest2();
  unitTest3();
}