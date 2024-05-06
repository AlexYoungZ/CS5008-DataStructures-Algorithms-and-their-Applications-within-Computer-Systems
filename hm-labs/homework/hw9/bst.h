// binary search tree header file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef HW9__BST_H_
#define HW9__BST_H_

// Create a node data struct to store data within our BST.
// In our case, we will stores 'integers'
typedef struct bstnode {
  int data;               // data each node holds
//  int freq;               // count the freq num
  struct bstnode *leftChild; // pointer to left child (if any)
  struct bstnode *rightChild;// pointer to right child (if any)
} bstnode_t;

// Our BST data structure
// Our BST holds a pointer to the root node in our BST.
typedef struct bst {
  // Size keeps track of how many items are in the BST.
  // Size should be incremented when we add.
  unsigned int size;
  bstnode_t *root;    // root points to the root node in our BST.
} bst_t;

bst_t *bst_create(int num) {
  bstnode_t *root = (bstnode_t *) malloc(sizeof(bstnode_t));
  bst_t *bst = (bst_t *) malloc(sizeof(bst_t));
  bst->size = 0;
  bst->root = root;
  bst->root->leftChild = NULL;
  bst->root->rightChild = NULL;
  bst->root->data = num;
  bst->size++;
  return bst;
}

bstnode_t *makeNode(int num) {
  bstnode_t *newNode = (bstnode_t *) malloc(sizeof(bstnode_t));
  newNode->data = num;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  return newNode;
}

int bst_empty(bst_t *t) {
  if (t == NULL) {
    return true;
  }
  if (t->root == NULL) {
    return true;
  } else {
    return false;
  }
}

int addHelper(bst_t *t, bstnode_t *node, bstnode_t *newNode) {
  if (newNode->data < node->data) {
    if (node->leftChild == NULL) {
      node->leftChild = newNode;
      t->size++;
      return 1;
    } else {
      addHelper(t, node->leftChild, newNode);
    }
  } else if (newNode->data > node->data) {
    if (node->rightChild == NULL) {
      node->rightChild = newNode;
      t->size++;
      return 1;
    } else {
      addHelper(t, node->rightChild, newNode);
    }
  }
  return 0;
}

int bst_add(bst_t *t, int item) {
  if (t == NULL) {
    return 0;
  }
  bstnode_t *newNode = makeNode(item);
  if (t->root == NULL) {
    t->root = newNode;
    t->size++;
    return 1;
  }
  return addHelper(t, t->root, newNode);
}

void inorder_print_helper(bstnode_t *node) {
  if (node == NULL) {
    return;
  }

  inorder_print_helper(node->leftChild);
  printf("%d ", node->data);
  inorder_print_helper(node->rightChild);
}

void preorder_print_helper(bstnode_t *node) {
  if (node == NULL) {
    return;
  }
  printf("%d ", node->data);
  preorder_print_helper(node->leftChild);
  preorder_print_helper(node->rightChild);
}

void postorder_print_helper(bstnode_t *node) {
  if (node == NULL) {
    return;
  }

  postorder_print_helper(node->leftChild);
  postorder_print_helper(node->rightChild);
  printf("%d ", node->data);
}

void bst_print(bst_t *t, int order) { // -1 for preorder, 0 for inorder, 1 for postorder
  if (t == NULL) return;
  if (order == 0) {
    inorder_print_helper(t->root);
  }
  if (order == -1) {
    preorder_print_helper(t->root);
  }
  if (order == 1) {
    postorder_print_helper(t->root);
  }
}

int sum_helper(bstnode_t *node) {
  if (node == NULL) {
    return 0;
  }
  int sum = node->data + sum_helper(node->leftChild) + sum_helper(node->rightChild);
  return sum;
}

int bst_sum(bst_t *t) {
  if (t == NULL) return 0;
  return sum_helper(t->root);
}

int find_helper(bstnode_t *node, int value) {
  if (node == NULL) {
    return 0;
  }
  if (node->data == value) {
    return 1;
  }
  if (node->data < value) {
    return find_helper(node->rightChild, value);
  }
  return find_helper(node->leftChild, value);
}

int bst_find(bst_t *t, int value) {
  if (t == NULL) return 0;
  if (t->root == NULL) return 0;
  return find_helper(t->root, value);
}

unsigned int bst_size(bst_t *t) {
  return t->size;
}

void free_helper(bstnode_t *node) {
  if (node == NULL) return;

  free_helper(node->leftChild);
  free_helper(node->rightChild);
  free(node);
}

void bst_free(bst_t *t) {
  if (t == NULL) {
    return;
  }
  free_helper(t->root);
}

#endif //HW9__BST_H_
