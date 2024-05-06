
#ifndef PRACTICUM__TREEMAP_H_
#define PRACTICUM__TREEMAP_H_
//
// to keep another order by keys, treemap is more suitable
//
#include <stdio.h>
#include <stdlib.h>

typedef struct treemap {
  int key;
  float value;
  struct treemap *left;
  struct treemap *right;
} treemap_t;

treemap_t *parent;

// add a node into treemap, O(logn), n is the number of nodes within the treemap
treemap_t *add(treemap_t *treemap, int key, float value) {
  if (treemap == NULL) {
    treemap = (treemap_t *) malloc(sizeof(treemap_t));
    treemap->left = NULL;
    treemap->right = NULL;
    treemap->key = key;
    treemap->value = value;
  } else if (key > treemap->key) {
    treemap->right = add(treemap->right, key, value);
  } else if (key < treemap->key) {
    treemap->left = add(treemap->left, key, value);
  } else if (key == treemap->key) {
    treemap->value = value;
  }
  return treemap;
}

void addNode(int key, float value) {
  parent = add(parent, key, value);
}

// Prints all of the keys and corresponding values of hashmap in ascending order, O(n) n is the
// number of nodes
void printTreemap(treemap_t *treemap) { // can change order
  if (treemap != NULL) {
    printTreemap(treemap->left);
    printf("key: %d, value: %f \n", treemap->key, treemap->value);
    printTreemap(treemap->right);
//  } else {
//    printf("this treemap is already empty, nothing to print\n");
  }
}

// free the treemap
void deleteTreemap(treemap_t *treemap) {
  if (treemap != NULL) {
    deleteTreemap(treemap->left);
    deleteTreemap(treemap->right);
    free(treemap);
  }
}

void destroy() {
  deleteTreemap(parent);
}

// get left most node, worst case O(n) in skewed tree, average O(logn)
treemap_t *getLeftmost(treemap_t *treemap) {
  if (treemap == NULL) {
    perror("cannot getLeftmost node since treemap is empty");
  }
  if (treemap != NULL && treemap->left != NULL) {
    return getLeftmost(treemap->left);
  }
  return treemap;
}

// delete node with given key, worst case O(n) in skewed tree, average O(logn)
treemap_t *deleteByKey(treemap_t *treemap, int key) {
  if (treemap != NULL) {
    if (key > treemap->key) {
      treemap->right = deleteByKey(treemap->right, key);
    } else if (key < treemap->key) {
      treemap->left = deleteByKey(treemap->left, key);
    } else if ((key == treemap->key) && (treemap->left == NULL) && (treemap->right == NULL)) {
      free(treemap);
      printf("this tree map is empty\n");
      return NULL;
    } else if (key == treemap->key) {
      treemap_t *tempLeft = treemap->left;
      treemap_t *tempRight = treemap->right;

      free(treemap);

      if (tempRight != NULL) {
        treemap_t *leftMostOnRight = getLeftmost(tempRight->left);
        if (leftMostOnRight != NULL) {
          leftMostOnRight->left = tempLeft;
        }
        treemap = tempRight;
      } else if (tempLeft != NULL) {
        treemap = tempLeft;
      }
    }
  } else {
    perror("given key is not existing");
  }
  return treemap;
}

void deleteNode(int key) {
  parent = deleteByKey(parent, key);
}

#endif //PRACTICUM__TREEMAP_H_
