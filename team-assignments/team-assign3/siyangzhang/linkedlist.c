#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// advantages over vector:
// 1. nodes can be insert or delete in the middle.
// 2. dynamic allocated, no need to define an initial size.
//
// disadvantages:
// 1. have to traverse from the head node to the node desired.
// 2. need dynamic memory allocation(less efficient than memory usage) and pointer manipulation,
// add additional complexity to code and increase the risk of memory leaks and segment faults
// 3. additional next pointer is required, creating larger overheads.
typedef struct node {
  int val;
  struct node *next;
} node_t;

typedef struct slist {
  node_t *head;
  node_t *tail;
  int size;
} slist_t;

/* insert at front of the list
 * complexity: O(1)
 * */
void push(slist_t *slist, int new_val) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = new_val;
  new_node->next = slist->head;

  slist->head = new_node;

  if (slist->tail == NULL) {
    slist->tail = new_node;
  }
  slist->size += 1;
}

/* append at end of the list
 * complexity: O(1)
 * */
void append(slist_t *slist, int new_val) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->val = new_val;
  new_node->next = NULL;

  if (slist->head == NULL) {
    slist->head = new_node;
    slist->tail = new_node;
    slist->size++;
    return;
  } else {
    slist->tail->next = new_node;
    slist->tail = slist->tail->next;
    slist->size++;
  }
}

/* add item at position pos in the List,
 * moving the items originally in positions pos through size()-1
 * one place to the right to make room
 * (error if pos is less than 0 or greater than size())
 * */
void add(slist_t *slist, int pos, int new_val) {
  node_t *cur = slist->head, *next;

  if (pos < 0) {
    perror("pos should be no less than 0");
  }

  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->val = new_val;

  if (pos == 0) {
    push(slist, new_val);
    return;
  }

  if (pos == slist->size) {
    append(slist, new_val);
    return;
  }

  if (pos > slist->size) {
    perror("pos should not be greater than size");
    return;
  }

  while (pos > 0) {
    next = cur->next;
    cur = next;
    pos--;
  }
  new_node->next = next;
  slist->size++;
}

/* delete the first node and return the value, given the head pointer
 * complexity: O(1)
 * */
int deleteFront(slist_t *slist) {
  int ret_val = -1;
  node_t *next_node;
  node_t *head = slist->head;
  node_t *tail = slist->tail;

  if (head == NULL) {
    return ret_val;
  }

  if (head == tail) { // (head==tail)!=NULL
    ret_val = head->val;
    free(tail);
    free(head);
    slist->size--;
    return ret_val;
  }

  // at least head -> tail
  ret_val = head->val;
  next_node = head->next;
  next_node->val = head->next->val;
  free(head);
  slist->head = next_node;
  slist->head->next = next_node->next;
  slist->size--;
  return ret_val;
}

/* delete a node with given value
 * complexity: O(n)
 * */
int delete_by_value(slist_t *slist, int val) {
  node_t *head = slist->head;
  node_t *prev, *cur;

  if (head == NULL) {
    return -1;
  }

  if (head->val == val) {
    return deleteFront(slist);
  }

  prev = head;
  cur = head->next;

  while (cur) {
    if (cur->val == val) {
      prev->next = cur->next;
      free(cur);
      slist->size--;
      return val;
    }
    prev = cur;
    cur = cur->next;
  }
  return -1;
}

/* remove a node with given index n and return node val
 * complexity: O(1)
 * */
int removeByIndex(slist_t *slist, int n) {
  int ret_val = -1;
  node_t *head = slist->head;
  node_t *cur, *prev;

  if (n == 0) {
    return deleteFront(slist);
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
  ret_val = cur->val;
  free(cur);
  slist->size--;

  return ret_val;
}

/* search the list and return the index of node with given data
 * complexity: O(n)
 * */
 int search(slist_t *slist, int val){
  node_t *cur = slist->head;
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
int get(slist_t *slist, int pos) {
  node_t *head = slist->head;
  node_t *cur = head, *next;

  if (pos < 0) {
    perror("pos should be no less than 0");
  }

  if (pos == 0) {
    return cur->val;
  }

  if (pos == slist->size - 1) {
    return slist->tail->val;
  }

  if (pos >= slist->size) {
    perror("pos should not be greater than or equal to size");
  }

  while (pos > 0) {
    next = cur->next;
    cur = next;
    pos--;
  }
  return cur->val;
}

/* return true iff the List is empty */
bool isEmpty(slist_t *slist) {
  node_t *head = slist->head;

  if (head == NULL) {
    return true;
  }
  return false;
}

/* return the number of items in the List */
int size(slist_t *slist) {
  if (slist->head == NULL) {
    return 0;
  }
  return slist->size;
}

/* delete the whole linked list with the given head node  */
void free_list(slist_t *slist) {
  node_t *head = slist->head;

  node_t *cur = head, *next;

  while (cur) {
    next = cur->next;
    free(cur);
    cur = next;
  }
  slist->size = 0;
}

/* print the data of a linked list from the given node  */
void print_list(slist_t *slist) {
  node_t *head = slist->head;
  node_t *cur = head;

  while (cur != NULL) {
    printf(" %d", cur->val);
    cur = cur->next;
  }
  getchar();

}

/* return true iff item is in the List
 * (i.e., there is an item x in the List such that x equals(item)) */
bool contains(slist_t *slist, int item) {
  if (search(slist, item) != -1) {
    return true;
  }
  return false;
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {

  slist_t *slist = (slist_t *) malloc(sizeof(slist_t));
  slist->head = slist->tail = NULL;
  slist->size = 0;

  printf("is this sll empty? %d\n", isEmpty(slist)); // 1
  push(slist, 108); // 108
  add(slist, 0, 1000); // 1000 108
  append(slist, 78); // 1000 108 78
  append(slist, 93); // 1000 108 78 93
  deleteFront(slist); // 108 78 93
  removeByIndex(slist, 1); // 108 93
  delete_by_value(slist, 108); // 93
  printf("the node index with given value is : %d\n", search(slist, 93)); // 0
  printf("the val in the first pos of sll is: %d\n", get(slist, 0)); // 93
  printf("does this sll contain 93? %d\n", contains(slist, 93)); // 1
  printf("the size of sll is: %d\n", size(slist)); // 1

  print_list(slist);

  free_list(slist);

}
