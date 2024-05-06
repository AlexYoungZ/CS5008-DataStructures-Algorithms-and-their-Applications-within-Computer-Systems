#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// advantages: operation is relatively faster for large dataset
// 1. can be traversed in both directions, forward and backward.
// 2. delete operation is more efficient if pointer to the node is given
// 3. insert a new node before a given node is more efficient
// (since don't need to traverse the list to find the pointer to the previous node)
//
// disadvantages:
// 1. every node requires extra space for previous pointer(especially for large dataset)
// 2. operations related with precious pointer require extra attention
typedef struct node {
  int val;
  struct node *next;
  struct node *prev;
} node_t;

typedef struct dlist {
  node_t *head;
  node_t *tail;
  int size;
} dlist_t;

/* insert at front of the list
 * complexity: O(1)
 * */
void push(dlist_t *dlist, int new_val) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = new_val;
  new_node->next = dlist->head;
  new_node->prev = NULL;

  dlist->head = new_node;

  if (dlist->tail == NULL) {
    dlist->tail = new_node;
  }
  dlist->size += 1;
}

/* append at end of the list
 * complexity: O(1)
 * */
void append(dlist_t *dlist, int new_val) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->val = new_val;
  new_node->next = NULL;

  if (dlist->head == NULL) {
    dlist->head = new_node;
    dlist->tail = new_node;
    dlist->size++;
    return;
  } else {
    dlist->tail->next = new_node;
    dlist->tail = dlist->tail->next;
    dlist->size++;
  }
}

/* insert a new node after the given node
 * complexity: O(n)
 * */
void insertAfter(dlist_t *dlist, node_t *prev, int new_val) {
  if (prev == NULL) {
    printf("given node can't be NULL\n");
    return;
  }

  node_t *new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = new_val;
  new_node->next = prev->next;
  prev->next = new_node;
  new_node->prev = prev;
  if (new_node->next != NULL) {
    new_node->next->prev = new_node;
  }
  dlist->size++;
}

/* add item at position pos in the List,
 * moving the items originally in positions pos through size()-1
 * one place to the right to make room
 * (error if pos is less than 0 or greater than size())
 * */
void add(dlist_t *dlist, int pos, int new_val) {
  node_t *cur = dlist->head, *next;

  if (pos < 0) {
    perror("pos should be no less than 0");
  }

  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->val = new_val;

  if (pos == 0) {
    push(dlist, new_val);
    return;
  }

  if (pos == dlist->size) {
    append(dlist, new_val);
    return;
  }

  if (pos > dlist->size) {
    perror("pos should not be greater than size");
    return;
  }

  while (pos > 0) {
    next = cur->next;
    cur = next;
    pos--;
  }
  insertAfter(dlist, cur->prev, new_val);
}

/* delete the first node and return the value, given the head pointer
 * complexity: O(1)
 * */
int deleteFront(dlist_t *dlist) {
  int ret_val = -1;
  node_t *next_node;
  node_t *head = dlist->head;
  node_t *tail = dlist->tail;

  if (head == NULL) {
    return ret_val;
  }

  if (head == tail) { // (head==tail)!=NULL
    ret_val = head->val;
    free(tail);
    free(head);
    dlist->size--;
    return ret_val;
  }

  // at least head -> tail
  ret_val = head->val;
  next_node = head->next;
  next_node->val = head->next->val;
  free(head);
  dlist->head = next_node;
  dlist->head->prev = NULL;
  dlist->head->next = next_node->next;
//  dlist->head = next_node->next->prev;
  dlist->size--;
  return ret_val;
}

/* remove a node with given index n and return node val
 * complexity: O(1)
 * */
int removeByIndex(dlist_t *dlist, int n) {
  int ret_val = -1;
  node_t *head = dlist->head;
  node_t *cur, *prev;

  if (n == 0) {
    return deleteFront(dlist);
  }

  prev = head;
  cur = head->next;

  for (int i = 0; i < n - 1; i++) {
    if (cur == NULL) {
      return ret_val;
    }
    cur = cur->next;
    prev = prev->next;
  }

  prev->next = cur->next;
  prev = cur->next->prev;
  ret_val = cur->val;
  free(cur);
  dlist->size--;

  return ret_val;
}

/* search the list and return the index of node with given val
 * complexity: O(n)
 * */
int search(dlist_t *dlist, int val) {
  node_t *cur = dlist->head;
  int retVal = -1;
  int index = 0;

  while (cur != NULL) {
    if (cur->val != val) {
      cur = cur->next;
      index++;
    } else {
      return index;
    }
  }
  return retVal;
}

/* return the item at position pos in the List
 * (error if pos is less than 0 or greater than or equal to size()) */
int get(dlist_t *dlist, int pos) {
  node_t *head = dlist->head;
  node_t *cur = head, *next;

  if (pos < 0) {
    perror("pos should be no less than 0");
  }

  if (pos == 0) {
    return cur->val;
  }

  if (pos == dlist->size - 1) {
    return dlist->tail->val;
  }

  if (pos >= dlist->size) {
    perror("pos should not be greater than or equal to size");
  }

  while (pos > 0) {
    next = cur->next;
    cur = next;
    pos--;
  }
  return cur->val;
}

/* print the val of a linked list from the given list  */
void printList(dlist_t *dlist) {
  node_t *head = dlist->head;
  node_t *cur = head;

  while (cur != NULL) {
    printf(" %d", cur->val);
    cur = cur->next;
  }
  getchar();
}

/* return true iff item is in the List
 * (i.e., there is an item x in the List such that x equals(item)) */
bool contains(dlist_t *dlist, int item) {
  if (search(dlist, item) != -1) {
    return true;
  }
  return false;
}

/* return the number of items in the List */
int size(dlist_t *dlist) {
  if (dlist->head == NULL) {
    return 0;
  }
  return dlist->size;
}

/* return true iff the List is empty */
bool isEmpty(dlist_t *dlist) {
  node_t *head = dlist->head;

  if (head == NULL) {
    return true;
  }
  return false;
}

/* delete the whole linked list  */
void free_list(dlist_t *dlist) {
  node_t *head = dlist->head;

  node_t *cur = head, *next;

  while (cur) {
    next = cur->next;
    free(cur);
    cur = next;
  }
  dlist->size = 0;
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {
  dlist_t *dlist = (dlist_t *) malloc(sizeof(dlist_t));
  dlist->head = dlist->tail = NULL;
  dlist->size = 0;

  printf("is this dll empty? %d\n", isEmpty(dlist)); // 1
  push(dlist, 108); // 108
  append(dlist, 78); // 108 78
  append(dlist, 93); // 108 78 93
  insertAfter(dlist, dlist->head, 88); // 108 88 78 93
  add(dlist, 1, 1000); // 108 1000 88 78 93
  deleteFront(dlist); // 1000 88 78 93
  removeByIndex(dlist, 1); // 1000 78 93
  printf("the node index with given value is : %d\n", search(dlist, 93)); // 2
  printf("the val in the first pos of dll is: %d\n", get(dlist, 0)); // 1000
  printf("does this dll contain 93? %d\n", contains(dlist, 93)); // 1
  printf("the size of dll is: %d\n", size(dlist)); // 3

  printList(dlist); // 1000 78 93

  free_list(dlist);
}

