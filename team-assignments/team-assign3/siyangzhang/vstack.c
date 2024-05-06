// stack implemented by vector
#include <stdio.h>
#include <stdlib.h>

typedef struct vStack {
  int top;
  int capacity;
  int size;
  int *vector;
} vstack_t;

vstack_t *newStack(int capacity) {
  vstack_t *vstack = (vstack_t *) malloc(sizeof(vstack_t));
  vstack->capacity = capacity;
  vstack->top  = -1;
  vstack->size = 0;
  vstack->vector = (int *) malloc(vstack->capacity * sizeof(int));
  return vstack;
}

int isFull(vstack_t *vstack) {
  return (vstack->top == vstack->capacity - 1);
}

int isEmpty(vstack_t *vstack) {
  return vstack->top == -1;
}

void push(vstack_t *vstack, int val) {
  if (isFull(vstack)) {
    return;
  }
  vstack->vector[++vstack->top] = val;
  vstack->size++;
}

int pop(vstack_t *vstack) {
  int retval = -1;

  if (isEmpty(vstack)) {
    perror("stack is empty\n");
    return retval;
  }

  retval = vstack->vector[vstack->top--];
  vstack->size--;

  return retval;
}

int peek(vstack_t* vstack){
  int retval = -1;

  if (isEmpty(vstack)) {
    perror("stack is empty\n");
    return retval;
  }

  retval = vstack->vector[vstack->top];
  return retval;
}

void print(vstack_t *vstack) {

  for (int i = 0; i < vstack->size; i++) {
    printf(" %d", vstack->vector[i]);
  }

  getchar();
}

int main(){
  vstack_t *vstack = newStack(100000);
  push(vstack, 71);
  push(vstack, 78);
  push(vstack, 93);
  push(vstack, 93);
  push(vstack, 108);
  pop(vstack); // 71 78 93 93

  print(vstack);

  printf("the top of this stack is: %d\n", peek(vstack));

  free(vstack->vector);
  free(vstack);
  return 0;
}