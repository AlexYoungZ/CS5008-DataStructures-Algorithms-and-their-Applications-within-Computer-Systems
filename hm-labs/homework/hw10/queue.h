#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
  int *data;
  int front;
  int back;
  int size;
} queue_t;

queue_t *createQueue(int size) {
  queue_t *queue = malloc(sizeof(queue_t));
  queue->data = malloc(size * sizeof(int));
  queue->front = -1;
  queue->back = -1;
  queue->size = size;
  return queue;
}

bool isEmpty(queue_t *queue) {
  if (queue->back == -1) {
    return true;
  } else {
    return false;
  }
}

void enqueue(queue_t *queue, int val) {
  if (queue->back == queue->size - 1) {
    printf("cannot enqueue since it's already full\n");
  } else {
    if (queue->front == -1) {
      queue->front = 0;
    }
    queue->back++;
    queue->data[queue->back] = val;
    queue->size++;
  }
}

int dequeue(queue_t *queue) {
  int element;
  if (isEmpty(queue)) {
    printf("cannot dequeue since it's already empty\n");
    element = -1;
  } else {
    element = queue->data[queue->front];
    queue->front++;
    queue->size--;
    if (queue->front > queue->back) {
      queue->front = queue->back = -1;
    }
  }
  return element;
}



