#ifndef TERNARY_SEARCH_TREE_H
#define TERNARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

// node of ternary search tree
typedef struct tstNode {
  char data;
  bool isLeaf;
  struct tstNode *left, *mid, *right;
} tstNode_t;

tstNode_t *newNode(char data);
tstNode_t *insert(tstNode_t *tstNode, const char *word);
bool isLeafNode(tstNode_t *tstNode);
bool contain(tstNode_t *root, const char *word);
tstNode_t *getNode(tstNode_t *tstNode, const char *word);
void printTST(tstNode_t* root, char* buffer, int level);
void deleteTST(tstNode_t *tstNode);

tstNode_t *createTSTFromFile(tstNode_t *root, const char *file);
void getCompletion(tstNode_t *node, char *prefix, slist_t *completions);
void autoComplete(tstNode_t *root, char *word);

#endif
