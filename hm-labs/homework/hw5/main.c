// use dynamic allocated vector to implement heap therefore no capacity limit
#include <stdio.h>
#include "heap.h"

void heapify(vector_t *vector, int i) { // index
  if (vector->size == 1) {
    printf("only one element within the heap, no need to heapify.");
    return;
  } else {
    int maxIndex = i;
    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;
    if (leftIdx < vector->size && vector->data[leftIdx] > vector->data[maxIndex]) {
      maxIndex = leftIdx;
    }
    if (rightIdx < vector->size && vector->data[rightIdx] > vector->data[maxIndex]) {
      maxIndex = rightIdx;
    }
    if (maxIndex != i) {
      swap(&vector->data[i], &vector->data[maxIndex]);
      heapify(vector, maxIndex);
    }
  }
}

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void insertHeap(vector_t *vector, int val) {
  if (vector->size == 0) {
    vector->data[0] = val;
    vector->size++;
  } else {
    vector->data[vector->size] = val;
    vector->size++;
    for (int i = vector->size / 2 - 1; i >= 0; i--) {
      heapify(vector, i);
    }
  }
}

int delete(vector_t *vector, int val) {
  int i, index;
  for (int i = 0; i < vector->size; i++) {
    if (val == vector->data[i]) {
      index = i;
      break;
    }
  }

  swap(&vector->data[index], &vector->data[vector->size - 1]);
  vector->size--;
  for (int i = vector->size / 2 - 1; i >= 0; i--) {
    heapify(vector, i);
  }

  return val;
}

int peek(vector_t *vector) {
  return vector->data[0];
}

void printHeap(vector_t *vector) {
  printf("heap :\n");

  for (int i = 0; i < vector->size; i++) {
    printf("%d ", vector->data[i]);
  }
  printf("\n");
}

int main() {
  vector_t *vector = createVector(2);

  insertHeap(vector, 3);
  insertHeap(vector, 6);
  insertHeap(vector, 7);
  insertHeap(vector, 9);
  insertHeap(vector, 1);

  printHeap(vector);

  delete(vector, 9);

  heapify(vector, vector->data[0]);
  printHeap(vector);

  printf("the max val of the heap is: %d\n", peek(vector));

  freeVector(vector);
}
