#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ORDER 10
#define MAXKEYS (ORDER-1)

struct node {
  int keyNum; // the number of keys within given node
  int keys[MAXKEYS];  // max key val array
  struct node *children[ORDER]; // child pointer array
  bool leaf; // if leaf node
};

typedef struct node *bTree;

bTree createBTree() {
  bTree root = malloc(sizeof(*root));

  root->leaf = true;
  root->keyNum = 0;

  return root;
}

void deleteTree(bTree tree) {
  int i;

  if (!tree->leaf) {
    for (int i = 0; i < tree->keyNum + 1; i++) {
      deleteTree(tree->children[i]);
    }
  }
  free(tree);
}

// binary search to find key index
static int binarySearchKey(int n, int key, const int *array) {
  int lo, hi, mid;
  lo = -1;
  hi = n;

  while (lo + 1 < hi) {
    mid = (lo + hi) / 2;
    if (array[mid] == key) {
      return mid;
    } else if (array[mid] < key) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return hi;
}

// return index for given key
int treeSearch(bTree tree, int key) {
  int index;
  if (tree->keyNum == 0) return 0;

  index = binarySearchKey(tree->keyNum, key, tree->keys);

  if (index < tree->keyNum && tree->keys[index] == key) {
    return true;
  } else {
    return (!tree->leaf && treeSearch(tree->children[index], key));
  }
}

// insert considering split and push up median case
bTree insertInternal(bTree tree, int key, int *median) {
  int index, mid;
  bTree newNode;

  index = binarySearchKey(tree->keyNum, key, tree->keys);

  if (index < tree->keyNum && tree->keys[index] == key) {
    return 0;
  }

  if (tree->leaf) { // shuffle by one to the right
    memmove(&tree->keys[index + 1],
            &tree->keys[index],
            sizeof(*(tree->keys)) * (tree->keyNum - index));
    tree->keys[index] = key;
    tree->keyNum++;
  } else {
    newNode = insertInternal(tree->children[index], key, &mid); // insert into children

    if (newNode) {
      // shuffle by one to the right
      memmove(&tree->keys[index + 1],
              &tree->keys[index],
              sizeof(*(tree->keys)) * (tree->keyNum - index));
      // append new node
      memmove(&tree->children[index + 2],
              &tree->children[index + 1],
              sizeof(*(tree->keys)) * (tree->keyNum - index));

      tree->keys[index] = mid;
      tree->children[index + 1] = newNode;
      tree->keyNum++;
    }
  }

  // split and push up
  if (tree->keyNum >= MAXKEYS) {
    mid = tree->keyNum / 2;
    *median = tree->keys[mid];

    newNode = malloc(sizeof(*newNode));
    newNode->keyNum = tree->keyNum - mid - 1;
    newNode->leaf = tree->leaf;

    memmove(newNode->keys, &tree->keys[mid + 1], sizeof(*(tree->keys)) * newNode->keyNum);
    if (!tree->leaf) {
      memmove(newNode->children, &tree->children[mid + 1], sizeof(*(tree->children)) *
          (newNode->keyNum + 1));
    }
    tree->keyNum = mid;

    return newNode;
  } else {
    return 0;
  }
}

void insert(bTree tree, int key) {
  bTree left;
  bTree right;
  int mid;

  right = insertInternal(tree, key, &mid);

  if (right) {
    left = malloc(sizeof(*left)); // if split when at root, need to make a new root;
    memmove(left, tree, sizeof(*tree));
    tree->keyNum = 1;
    tree->leaf = 0;
    tree->keys[0] = mid;
    tree->children[0] = left;
    tree->children[1] = right;
  }
}

void treePrint(bTree tree) {
  int i;
  if (tree) {
    for (int i = 0; i < tree->keyNum; i++) {
      treePrint(tree->children[i]);
      printf("%d ", tree->keys[i]);
    }
  }
}

int main() {
  int i;
  bTree tree;

  tree = createBTree();

  insert(tree, 6);
  insert(tree, 3);
  insert(tree, 1);
  insert(tree, 9);
  insert(tree, 2);

  treePrint(tree);
//  deleteTree(root);

  return 0;
}













