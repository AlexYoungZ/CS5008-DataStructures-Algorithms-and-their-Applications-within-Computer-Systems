// stack implemented by linked-list
#include <stdio.h>
#include <stdlib.h>
//#include "stack.h"

typedef struct node {
  int val;
  struct node *next;
} node_t;

typedef struct sllStack {
  node_t *top;
  int size;
} sllstack_t;

node_t *newNode(int val) {
  node_t *node = (node_t *) malloc(sizeof(node_t));
  node->val = val;
  node->next = NULL;
  return node;
}

sllstack_t *newStack() {
  sllstack_t *sllstack = (sllstack_t *) malloc(sizeof(sllstack_t));
  sllstack->top = NULL;
  sllstack->size = 0;
  return sllstack;
}


int isEmpty(sllstack_t *sllstack) {
  return sllstack->top == NULL;
}

// O(1)
void push(sllstack_t *sllstack, int val) {
  node_t *node = newNode(val);

  node->val = val;
  node->next = sllstack->top;
  sllstack->top = node;
  sllstack->size++;
}

// O(1)
int pop(sllstack_t *sllstack) {
  int retval = -1;

  if (isEmpty(sllstack)) {
    perror("stack is empty\n");
    return retval;
  }

  retval = sllstack->top->val;
  node_t *temp = sllstack->top;
  sllstack->top = sllstack->top->next;
  free(temp);
  sllstack->size--;

  return retval;
}

// O(1)
int peek(sllstack_t* sllstack){
  int retval = -1;

  if (isEmpty(sllstack)) {
    perror("stack is empty\n");
    return retval;
  }

  retval = sllstack->top->val;
  return retval;
}

void print(sllstack_t *sllstack) {
  node_t *cur = sllstack->top;

  while (cur != NULL) {
    printf(" %d", cur->val);
    cur = cur->next;
  }

  printf("\nsllStack top : %d \n", peek(sllstack));

  getchar();
}

void freeStack(sllstack_t *sllstack){
  node_t *cur = sllstack->top, *next;

  while (cur != NULL) {
    next = cur->next;
    free(cur);
    cur = next;
  }
  sllstack->size = 0;
}

int main(){
  sllstack_t *sllstack = newStack();
  push(sllstack, 71);
  push(sllstack, 78);
  push(sllstack, 93);
  push(sllstack, 93);
  push(sllstack, 108);
  pop(sllstack); // 71 78 93 93 <- top

  print(sllstack);


  freeStack(sllstack);
  free(sllstack);
  return 0;
}