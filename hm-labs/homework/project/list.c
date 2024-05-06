#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

// create a new node containing a char array of word
listNode_t *createNode(const char *newData){
  listNode_t *newNode = (listNode_t *) malloc(sizeof(listNode_t));
  char *data = malloc(strlen(newData) + 1);
  strcpy(data,newData);
  if (newNode == NULL) {
    printf("Fail to create a new list node\n");
  }
  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

// create an empty single-linked-list
slist_t *createList(){
  slist_t *newList = (slist_t *) malloc(sizeof(slist_t));
  if (newList == NULL) {
    printf("Fail to create new list\n");
  }
  newList->head = createNode("");
  newList->tail = newList->head;

  return newList;
}

// create a new node with given word and append to the end of list
// O(1)
void append(slist_t *slist, const char *word){
  listNode_t *newNode = createNode(word);
  slist->tail->next = newNode;
  slist->tail = newNode;
}

// print the content of each node within given list
// one pass, O(n) where n is the number of nodes
void printList(slist_t *slist){
  listNode_t *node = slist->head;

  while (node) {
    puts(node->data);
    node = node->next;
  }
}

// free the list and its content data
// one pass, O(n) where n is the number of nodes
void deleteList(slist_t *slist){
  listNode_t *cur = slist->head;
  listNode_t *prev;

  while (cur != NULL) {
    prev = cur;
    cur = cur->next;

    free(prev->data);
    free(prev);
  }
  free(slist);
}