#include <stdio.h>
#include "bst.h"

// Testing allocation
int unitTest1() {
  int result;
  bst_t *testBST = bst_create(10);
  if (testBST != NULL) {
    result = 1;
  } else {
    result = 0;
  }
  bst_free(testBST);
  return result;
}

// Testing func bst_empty
int unitTest2() {
  int result;
  bst_t *testBST = bst_create(10);
  if (bst_empty(testBST)) {
    result = 0;
  } else {
    result = 1;
  }
  bst_free(testBST);
  return result;
}

// Testing func bst_empty
int unitTest3() {
  int result;
  bst_t *testBST = NULL;
  if (bst_empty(testBST)) {
    result = 1;
  } else {
    result = 0;
  }
  bst_free(testBST);
  return result;
}

// Testing func bst_add
int unitTest4() {
  int result;
  bst_t *testBST = bst_create(10);

  if (bst_add(testBST, 15) && testBST->root->rightChild->data == 15) {
    result = 1;
  } else {
    result = 0;
  }
  bst_free(testBST);
  return result;
}

// Testing func bst_print
int unitTest5() {
  int result;
  bst_t *testBST = bst_create(10);
  bst_add(testBST, 15);
  bst_add(testBST, 4);
  bst_add(testBST, 7);
  bst_add(testBST, 17);
  bst_add(testBST, 20);
  printf("insert order: 10, 15, 4, 7, 17, 20\n");
  printf("inorder traversal\n");
  bst_print(testBST, 0);
  printf("\npreorder traversal\n");
  bst_print(testBST, -1);
  printf("\npost traversal\n");
  bst_print(testBST, 1);

  bst_free(testBST);
  return result = 1;

}

// Testing func bst_sum
int unitTest6() {
  int result;
  bst_t *testBST = bst_create(10);
  bst_add(testBST, 15);
  bst_add(testBST, 4);
  bst_add(testBST, 7);
  bst_add(testBST, 17);
  bst_add(testBST, 20);
  if (bst_sum(testBST) == 73) {
    result = 1;
  } else {
    result = 0;
  }

  bst_free(testBST);
  return result;
}

// Testing func bst_find
int unitTest7() {
  int result;
  bst_t *testBST = bst_create(10);
  bst_add(testBST, 15);
  bst_add(testBST, 4);
  bst_add(testBST, 7);
  bst_add(testBST, 17);
  bst_add(testBST, 20);
  if (bst_find(testBST, 20)) {
    result = 1;
  } else {
    result = 0;
  }
  bst_free(testBST);
  return result;
}

// Testing func bst_size
int unitTest8() {
  int result;
  bst_t *testBST = bst_create(10);
  bst_add(testBST, 15);
  bst_add(testBST, 4);
  bst_add(testBST, 7);
  bst_add(testBST, 17);
  bst_add(testBST, 20);
  if (bst_size(testBST) == 6) {
    result = 1;
  } else {
    result = 0;
  }
  bst_free(testBST);
  return result;
}

int (*unitTests[])(int) ={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
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
    printf("========unitTest %d========\n", counter + 1);
    if (1 == unitTests[counter](1)) {
      printf("passed test %d\n", counter + 1);
      testsPassed++;
    } else {
      printf("failed test %d, missing functionality, or incorrect test\n", counter + 1);
    }
    counter++;
  }

  printf("%d of %d tests passed\n", testsPassed, counter);

  return 0;
}

