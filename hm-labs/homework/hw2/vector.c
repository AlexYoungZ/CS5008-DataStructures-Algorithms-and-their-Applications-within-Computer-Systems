#include <stdio.h>
#include <stdlib.h>

// from prof Vito's vector implementation
// advantages:
// 1. relatively simpler than linked list, easy to create
// 2. space required is less, especially for large datasets
//
// disadvantages:
// 1. operations involve traversing is slower than linked list, not as easy to manipulate

typedef struct vector {
  int *data;
  int size;
  int capacity;
} vector_t;

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
  for (int i = 0; i < vector->size; i++) {
    if (vector->data[i] == val) {
      return printf("index of %d in the vector is %d \n", val, index);
    }
    index++;
  }
  return printf("%d is not in the vector\n", val);
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
  printf("\n");
}

/* insert an element with given position
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

/* insert at front of the vector
 * complexity: O(n)
 * */
int push(vector_t *vector, int element) {
  return insert(vector, 0, element);
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {
  vector_t *vector = createVector(2);

  append(vector, 93);
  append(vector, 78);
  append(vector, 71);
  push(vector, 93);
  insert(vector, 0, 108);

  print(vector);

  search(vector, 93);

  freeVector(vector);
  return 0;
}

