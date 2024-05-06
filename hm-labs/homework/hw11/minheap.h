#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct heapNode {
  int data;
  int dist;
} heapNode_t;

typedef struct minHeap {
  int size;
  int capacity;
  int *pos;
  heapNode_t **array;
} minHeap_t;

heapNode_t *createHeapNode(int val, int dist) {
  heapNode_t *newHeapNode = malloc(sizeof(heapNode_t));
  newHeapNode->data = val;
  newHeapNode->dist = dist;
  return newHeapNode;
}

minHeap_t *createMinHeap(int capacity) {
  minHeap_t *minHeap = malloc(sizeof(minHeap_t));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (heapNode_t **) malloc(capacity * sizeof(heapNode_t*));
  minHeap->pos = (int *) malloc(capacity * sizeof(int));
  return minHeap;
}

void swap(heapNode_t *a, heapNode_t *b) {
  heapNode_t temp = *a;
  *a = *b;
  *b = temp;
}

// heapify with given index
void heapify(minHeap_t *minHeap, int index) {
  int minIndex = index;
  int leftIdx = 2 * index + 1;
  int rightIdx = 2 * index + 2;

  if (leftIdx < minHeap->size && minHeap->array[leftIdx]->dist < minHeap->array[minIndex]->dist) {
    minIndex = leftIdx;
  }

  if (rightIdx < minHeap->size && minHeap->array[rightIdx]->dist < minHeap->array[minIndex]->dist) {
    minIndex = rightIdx;
  }

  if (minIndex != index) {
    heapNode_t* minNode = minHeap->array[minIndex];
    heapNode_t* indexNode = minHeap->array[index];
    // swap index
    minHeap->pos[minNode->data] = index;
    minHeap->pos[indexNode->data] = minIndex;
    // swap node
    swap(minHeap->array[minIndex], minHeap->array[index]);

    heapify(minHeap, minIndex);
  }
}

int isEmptyHeap(minHeap_t *minHeap) {
  return minHeap->size == 0;
}

heapNode_t *extractMin(minHeap_t *minHeap) {
  if (isEmptyHeap(minHeap)) {
    return NULL;
  }

  heapNode_t *root = minHeap->array[0];

  // exchange with last node
  heapNode_t* lastNode = minHeap->array[minHeap->size - 1];
  minHeap->array[0] = lastNode;

  // update position
  minHeap->pos[root->data] = minHeap->size - 1;
  minHeap->pos[lastNode->data] = 0;

  --minHeap->size;
  heapify(minHeap, 0);

  return root;
}

void decreaseKey(minHeap_t *minHeap, int val, int dist) {
  int index = minHeap->pos[val];
  minHeap->array[index]->dist = dist;

  // log(n) loop
  while (index && (minHeap->array[index]->dist < minHeap->array[(index - 1) / 2]->dist)) {
    // swap
    minHeap->pos[minHeap->array[index]->data] = (index - 1) / 2;
    minHeap->pos[minHeap->array[(index - 1) / 2]->data] = index;
    swap(minHeap->array[index], minHeap->array[(index - 1) / 2]);

    // move to parent index
    index = (index - 1) / 2;
  }
}

bool vertexExist(minHeap_t *minHeap, int data) {
  if (minHeap->pos[data] < minHeap->size) {
    return true;
  }
  return false;
}

void printResult(int dist[], int n) {
  printf("Vertex    Distance from source\n");
  for (int i = 0; i < n; i++) {
    printf("%d \t\t %d\n", i, dist[i]);
  }
}

void printMST(int arr[], int n){
  for (int i = 1; i < n; i++) {
    printf("%d - %d\n", arr[i], i);
  }
}

#endif














