/*
Singly-linked list used to store autocompletion results
*/
#ifndef LIST_H
#define LIST_H

typedef struct listNode {
  char *data;
  struct listNode *next;
} listNode_t;

typedef struct slist {
  struct listNode *head;
  struct listNode *tail;
} slist_t;

listNode_t *createNode(const char *data);
slist_t *createList();
void append(slist_t *slist, const char *word);
void printList(slist_t *slist);
void deleteList(slist_t *slist);

#endif //LIST_H
