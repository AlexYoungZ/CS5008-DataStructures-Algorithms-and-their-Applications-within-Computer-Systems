#include <stdio.h>
#include <stdlib.h>

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

/* insert at front of the list
 * complexity: O(1)
 * */
void push(node_t **p_head, int new_val) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = new_val;

  new_node->next = (*p_head);
  new_node->prev = NULL;

  if (*p_head != NULL) {
    (*p_head)->prev = new_node;
  }

  (*p_head) = new_node;

}

/* append at end of the list
 * complexity: O(1)
 * */
void append(node_t **p_head, int new_val) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));

  node_t *last = *p_head;

  new_node->val = new_val;

  new_node->next = NULL;

  if (*p_head == NULL) {
    new_node->prev = NULL;
    *p_head = new_node;
    return;
  }

  while (last->next != NULL) {
    last = last->next;
  }

  last->next = new_node;
  new_node->prev = last;

}

/* insert a new node after the given node
 * complexity: O(n)
 * */
void insertAfter(node_t *prev_n, int new_val) {
  if (prev_n == NULL) {
    printf("given node can't be NULL");
    return;
  }

  node_t *new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = new_val;

  new_node->next = prev_n->next;
  prev_n->next = new_node;
  new_node->prev = prev_n;
  if (new_node->next != NULL) {
    new_node->next->prev = new_node;
  }
}

/* delete a node with given head pointer and node to delete
 * complexity: O(1)
 * */
void delete(node_t **p_head, node_t *n_del) {
  if (*p_head == NULL || n_del == NULL) {
    return;
  }

  if (*p_head == n_del) {
    *p_head = n_del->next;
  }

  if (n_del->next != NULL) {
    n_del->next->prev = n_del->prev;
  }

  if (n_del->prev != NULL) {
    n_del->prev->next = n_del->next;
  }

  free(n_del);

}

/* search the list and return the index of node with given val
 * complexity: O(n)
 * */
int search(node_t *head, int val) {
  int retval = -1;
  node_t *cur = head;
  int index = 0;
  while (cur != NULL) {
    if (cur->val != val) {
      cur = cur->next;
      index++;
    } else {
      return index;
    }
  }
  return retval;
}

/* print the val of a linked list from the given node  */
void printList(node_t *node) {
  while (node != NULL) {
    printf(" %d", node->val);
    node = node->next;
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

//2018, 108 wins
//2017, 93 wins
//2016, 93 wins
//2015, 78 wins
//2014, 71 wins
int main() {
  node_t *head = NULL;
  append(&head, 93); // 93
  push(&head, 108); // 108 93
  insertAfter(head, 93); // 108 93 93
  append(&head, 71); // 108 93 93 71
  insertAfter(head->next->next, 78); // 108 93 93 78 71
  append(&head, 100); // // 108 93 93 78 71 100
  delete(&head,head->next->next->next->next->next);

  printf("double linked list is: \n");
  printList(head); //  108 93 93 78 71

  printf("\nsearch node index with value 78: %d\n", search(head, 78));

  getchar();

  free_list(head);

//  return 0;
}

