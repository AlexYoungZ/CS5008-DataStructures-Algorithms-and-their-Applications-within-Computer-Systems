// queue implemented by linked-list
#include <stdio.h>
#include <stdlib.h>
//#include "linkedlist.c"

typedef struct node {
  int val;
  struct node *next;
} node_t;

typedef struct sllQueue {
  node_t *front;
  node_t *end;
  int size;
} sllqueue_t;

node_t *newNode(int val) {
  node_t *node = (node_t *) malloc(sizeof(node_t));
  node->val = val;
  node->next = NULL;
  return node;
}

sllqueue_t *newQueue() {
  sllqueue_t *sllqueue = (sllqueue_t *) malloc(sizeof(sllqueue_t));
  sllqueue->front = NULL;
  sllqueue->end = NULL;
  sllqueue->size = 0;
  return sllqueue;
}

// O(1)
void enqueue(sllqueue_t *sllqueue, int val) {
  node_t *new_node = newNode(val);

  if (sllqueue->end == NULL) {
    sllqueue->front = new_node;
    sllqueue->end = new_node;
    sllqueue->size++;
    return;
  }

  sllqueue->end->next = new_node;
  sllqueue->end = new_node;
  sllqueue->size++;
}

// O(1)
int dequeue(sllqueue_t *sllqueue) {
  int retval = -1;
  if (sllqueue->front == NULL) {
    perror("queue is empty\n");
    return retval;
  }

  node_t *head = sllqueue->front;
  retval = head->val;

  sllqueue->front = sllqueue->front->next;

  if (sllqueue->front == NULL) {
    sllqueue->end = NULL;
  }

  free(head);
  sllqueue->size--;
  return retval;
}

void print(sllqueue_t *sllqueue) {
  node_t *cur = sllqueue->front;

  while (cur != NULL) {
    printf(" %d", cur->val);
    cur = cur->next;
  }

  printf("\nsllQueue front : %d \n", sllqueue->front->val);
  printf("sllQueue end : %d", sllqueue->end->val);

  getchar();
}

void freeQueue(sllqueue_t *sllqueue){
  node_t *cur = sllqueue->front, *next;

  while (cur != NULL) {
    next = cur->next;
    free(cur);
    cur = next;
  }
  sllqueue->size = 0;
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {
  sllqueue_t *sllqueue = newQueue();
  enqueue(sllqueue, 71);
  enqueue(sllqueue, 78);
  enqueue(sllqueue, 93);
  enqueue(sllqueue, 93);
  enqueue(sllqueue, 108);

  dequeue(sllqueue); // 78 93 93 108

  print(sllqueue);

  freeQueue(sllqueue);
  free(sllqueue);
  return 0;
}
