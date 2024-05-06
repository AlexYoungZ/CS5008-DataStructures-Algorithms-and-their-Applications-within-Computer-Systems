#include <stdio.h>
#include <stdlib.h>

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

/* print the data of a linked list from the given node  */
void print_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf(" %d", current->val);
    current = current->next;
  }
}

/* delete the whole linked list with the given head node  */
void free_list(node_t *head) {
  node_t *current = head, *next = head;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }
}

/* insert at front of the list
 * complexity: O(1)
 * */
void push(node_t **head, int val) {
  node_t *new_node;
  new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

/* append at end of the list
 * complexity: O(n)
 * */
void append(node_t *head, int val) {
  node_t *cur = head;
  while (cur->next != NULL) {
    cur = cur->next;
  }

  cur->next = (node_t *) malloc(sizeof(node_t));
  cur->next->val = val;
  cur->next->next = NULL;
}

/* delete the first node and return the value, given the head pointer
 * complexity: O(1)
 * */
int deleteFront(node_t **head) {
  int ret_val = -1;
  node_t *next_node = NULL;

  if (*head == NULL) {
    return -1;
  }

  next_node = (*head)->next;
  ret_val = (*head)->val;
  free(*head);
  *head = next_node;

  return ret_val;
}

/* delete a node with given value
 * complexity: O(n)
 * */
int delete_by_value(node_t **head, int val) {
  node_t *prev, *cur;

  if (*head == NULL) {
    return -1;
  }

  if ((*head)->val == val) {
    return deleteFront(head);
  }

  prev = cur = (*head)->next;

  while (cur) {
    if (cur->val == val) {
      prev->next = cur->next;
      free(cur);
      return val;
    }
    prev = cur;
    cur = cur->next;
  }
  return -1;
}

/* delete a node with given index n
 * complexity: O(1)
 * */
int delete_by_index(node_t **head, int n) {
  int ret_val = -1;
  node_t *cur = *head;
  node_t *temp = NULL;

  if (n == 0) {
    return deleteFront(head);
  }

  for (int i = 0; i < n - 1; i++) {
    if (cur->next == NULL) {
      return -1;
    }
    cur = cur->next;
  }

  temp = cur->next;
  ret_val = temp->val;
  cur->next = temp->next;
  free(temp);

  return ret_val;
}

/* search the list and return the index of node with given data
 * complexity: O(n)
 * */
int search(node_t *head, int val) {
  int index = 0;
  while (head != NULL) {
    if (head->val != val) {
      head = head->next;
      index++;
    } else {
      return index;
    }
  }
  return printf("%d is not in the list", val);
}

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {

  node_t *red_sox = (node_t *) malloc(sizeof(node_t));
  red_sox->val = 93;
  red_sox->next = NULL;
  push(&red_sox, 108); // 108 93
  append(red_sox, 78); // 108 93 78

  push(&red_sox, 1000); // 1000 108 93 78
  deleteFront(&red_sox); // 108 93 78
  append(red_sox, 999); // 108 93 78 999
  delete_by_index(&red_sox, 3); // 108 93 78
  delete_by_value(&red_sox, 78); // 108 93

  print_list(red_sox);

  printf("\n the node index with given value is : %d\n", search(red_sox, 93));

  free_list(red_sox);

}
