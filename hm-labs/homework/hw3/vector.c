#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"
// from prof Vito's vector implementation
// advantages:
// 1. relatively simpler than linked list, easy to create
// 2. space required is less, especially for large datasets
//
// disadvantages:
// 1. operations involve traversing is slower than linked list, not as easy to manipulate



/* return the number of items in the List */
int size(vector_t *vector) {
  return vector->size;
}

vector_t *createVector(int initCapacity) {
  vector_t *vector = (vector_t *) malloc(sizeof(vector_t));
  if (vector == NULL) {
    return NULL;
  }

  vector->data = (int *) malloc(sizeof(int) * initCapacity);
  vector->size = 0;
  vector->capacity = initCapacity;
  return vector;
}

void freeVector(vector_t *vector) {
  if (vector == NULL) {
    return;
  }

  if (vector->data != NULL) {
    free(vector->data);
  }

  free(vector);
}

/* search the vector and return the index
 * complexity: O(n)
 * */
int search(vector_t *vector, int val) {
  int index = 0;
  int retVal = -1;

  for (int i = 0; i < vector->size; i++) {
    if (vector->data[i] == val) {
      printf("index of %d in the vector is %d \n", val, index);
      return 1;
    }
    index++;
  }
  printf("%d is not in the vector\n", val);
  return retVal;
}

/* return the item at position pos in the List
 * (error if pos is less than 0 or greater than or equal to size()) */
int get(vector_t *vector, int pos) {

  if (pos < 0 || pos >= vector->size) {
    perror("pos should be no less than 0 and not greater than or equal to size of vector");
  }

  for (int i = 0; i < vector->size; i++) {
    if (pos == i) {
      return vector->data[i];
    }
  }
}

/* resize the vector into double capacity
 * complexity: O(n)
 * */
int resize(vector_t *vector) {
  if (vector == NULL) {
    return 0;
  }

  vector->capacity = vector->capacity * 2;
  int *newData = (int *) malloc(sizeof(int) * vector->capacity);

  if (newData == NULL || vector->data == NULL) {
    return 0;
  }

  for (int i = 0; i < vector->size; i++) {
    newData[i] = vector->data[i];
  }

  free(vector->data);
  vector->data = newData;
  return 1;
}

/* append at end of the vector
 * worse complexity: O(n) have to resize and copy
 * average complexity: O(1)
 * */
int append(vector_t *vector, int element) {
  if (vector == NULL) {
    return 0;
  }

  if (vector->data == NULL) {
    return 0;
  }

  if (vector->size == vector->capacity) {
    int resizeStatus = resize(vector);
    if (resizeStatus == 0) {
      return 0;
    }
  }

  vector->data[vector->size] = element;
  vector->size += 1;
  return 1;
}

void print(vector_t *vector) {
  if (vector == NULL) {
    return;
  }

  if (vector->data == NULL) {
    return;
  }

  for (int i = 0; i < vector->size; i++) {
    printf("%d ", vector->data[i]);
  }
  getchar();
}

/* insert(add) an element with given position
 * complexity: O(n)
 * */
int insert(vector_t *vector, int pos, int element) {
  if (vector == NULL || pos < 0) {
    return 0;
  }

  if (pos == vector->size) {
    return append(vector, element);
  }

  if (vector->size == vector->capacity) {
    int resizeStatus = resize(vector);
    if (resizeStatus == 0) {
      return 0;
    }
  }

  if (vector->data == NULL) {
    return 0;
  }

  for (int i = vector->size - 1; i >= pos; i--) {
    vector->data[i + 1] = vector->data[i];
  }

  vector->data[pos] = element;
  vector->size += 1;
  return 1;
}

/* remove and return the item at position pos in the List,
 * moving the items originally in positions pos+1 through size()-1
 * one place to the left to fill in the gap
 * (error if pos is less than 0 or greater than or equal to size()) */
int removeByPos(vector_t *vector, int pos) { // shrink the vector
  if (pos < 0 || pos >= vector->size) {
    perror("pos should be no less than 0 and not greater than or equal to size of vector");
  }

  if (vector == NULL) {
    return 0;
  }

  int val = vector->data[pos];
//  if (pos + 1 == vector->size) {
//    vector->data[pos] = NULL;
//  }

  for (int i = vector->size - 1; i >pos; i--) {
    vector->data[i - 1] = vector->data[i];
  }
  vector->size -= 1;
  return val;
}

/* return true iff the List is empty */
bool isEmpty(vector_t *vector) {
  if (vector->size == 0) {
    return true;
  }
  return false;
}

/* insert at front of the vector
 * complexity: O(n)
 * */
int push(vector_t *vector, int element) {
  return insert(vector, 0, element);
}

/* return true iff item is in the List
 * (i.e., there is an item x in the List such that x equals(item)) */
bool contains(vector_t *vector, int val) {
  if (search(vector, val) == -1) {
    return false;
  }
  return true;
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {
  vector_t *vector = createVector(2);
  printf("is this vector empty? %d\n", isEmpty(vector));

  append(vector, 93); // 93
  append(vector, 78); // 93 78
  append(vector, 71); // 93 78 71
  push(vector, 93); // 93 93 78 71
  insert(vector, 0, 108); // 108 93 93 78 71
  append(vector, 999); // 108 93 93 78 71 999
  removeByPos(vector, 5); // 108 93 93 78 71

  printf("does this vector contain 71? %d\n", contains(vector, 71));

  printf("the size of vector is: %d\n", size(vector));

  printf("the val in the third pos of vector is: %d\n", get(vector, 3));

  print(vector);

  search(vector, 93);

  freeVector(vector);
  return 0;
}

