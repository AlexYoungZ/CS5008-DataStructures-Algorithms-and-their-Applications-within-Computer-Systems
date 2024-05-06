// circular queue implemented by vector
#include <stdio.h>
#include <stdlib.h>
//#include "linkedlist.c"

typedef struct vQueue {
  int front, end;
  int size;
  int capacity;
  int *vector;
} vqueue_t;

vqueue_t *newQueue(int capacity) {
  vqueue_t *vqueue = (vqueue_t *) malloc(sizeof(vqueue_t));
  vqueue->capacity = capacity;
  vqueue->front = 0;
  vqueue->end = capacity - 1;
  vqueue->size = 0;
  vqueue->vector = (int *) malloc(vqueue->capacity * sizeof(int));
  return vqueue;
}

int isFull(vqueue_t *vqueue) {
  return (vqueue->size == vqueue->capacity);
}

int isEmpty(vqueue_t *vqueue) {
  return (vqueue->size == 0);
}

void enqueue(vqueue_t *vqueue, int val) {
  if (isFull(vqueue)) {
    return;
  }
  vqueue->end = (vqueue->end + 1) % (vqueue->capacity);
  vqueue->vector[vqueue->end] = val;
  vqueue->size++;
}

int dequeue(vqueue_t *vqueue) {
  int retval = -1;

  if (isEmpty(vqueue)) {
    perror("queue is empty\n");
    return retval;
  }

  retval = vqueue->vector[vqueue->front];
  vqueue->size--;

  for (int i = 0; i < vqueue->size; i++) {
    if (vqueue->vector[i + 1] == vqueue->end) {
      return retval;
    }
   vqueue->vector[i] = vqueue->vector[i+1];
  }
  return retval;
}

void print(vqueue_t *vqueue) {

  for (int i = 0; i < vqueue->size; i++) {
    printf(" %d", vqueue->vector[i]);
  }

  printf("\nvQueue front : %d \n", vqueue->vector[vqueue->front]);
  printf("vQueue end : %d", vqueue->vector[vqueue->end]);
  getchar();
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {
  vqueue_t *vqueue = newQueue(100000);
  enqueue(vqueue, 71);
  enqueue(vqueue, 78);
  enqueue(vqueue, 93);
  enqueue(vqueue, 94);
  enqueue(vqueue, 108);

  int a = dequeue(vqueue);
  printf("deque value is %d\n", a); // 71
  printf("vqueue size is %d\n", vqueue->size); // 4


  print(vqueue); // front -> 78 93 94 108 <- end

  free(vqueue->vector);
  free(vqueue);
  return 0;
}








