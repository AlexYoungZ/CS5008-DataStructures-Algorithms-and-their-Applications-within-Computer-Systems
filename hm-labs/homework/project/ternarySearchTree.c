#include <string.h>
#include "list.h"
#include "ternarySearchTree.h"

// create a new ternary search tree node
tstNode_t *newNode(char data) {
  tstNode_t *newNode = (tstNode_t *) malloc(sizeof(tstNode_t));
  if (newNode == NULL) {
    printf("Fail to create a new ternary search tree node\n");
  }
  newNode->data = data;
  newNode->isLeaf = false;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->mid = NULL;

  return newNode;
}

// recursively insert new word into given ternary search tree and return the node
// average-case: O(logN) the height of the tree where N is the number of nodes
// worst-case: O(N) total skew tree
// space complexity: the length of word O(L)
tstNode_t *insert(tstNode_t *tstNode, const char *word) {
  // create a new node if not exist
  if (!tstNode) {
    tstNode = newNode(*word);
  }

  // if new word is not given, mark the node as leaf node
  if (!(*word)) {
    tstNode->isLeaf = true;
  }

  // if current char of word is smaller than node's character, insert into the node's left subtree
  if (*word < tstNode->data) {
    tstNode->left = insert(tstNode->left, word);
  } else if (*word == tstNode->data) {
    // if current char of word is equal to node's character and there are still char left in word,
    // goto the node's mid subtree and try next char
    if (*word != '\0') {
      tstNode->mid = insert(tstNode->mid, ++word);
    } else {
      // all char is inserted, mark the last node as leaf node
      tstNode->isLeaf = true;
    }
  } else {
    // if current char of word is larger than node's character, insert into the node's right subtree
    tstNode->right = insert(tstNode->right, word);
  }
  return tstNode;
}


// check if given ternary trie node is a leaf node
// constant time
bool isLeafNode(tstNode_t *tstNode) {
  if (!tstNode->left && !tstNode->mid && !tstNode->right) {
    return true;
  }
  return false;
}

// search operation, get the node mark the end of the given word
// average-case: O(logN) the height of the tree where N is the number of nodes
// worst-case: O(N) total skew tree
tstNode_t *getNode(tstNode_t *tstNode, const char *word) {
  if (!tstNode) {
    return NULL;
  }

  if (*word != '\0') {
    if (*word < tstNode->data) {
      return getNode(tstNode->left, word);
    } else if (*word == tstNode->data) {
      if (*word != '\0') {
        return getNode(tstNode->mid, ++word);
      }
    } else {
      return getNode(tstNode->right, word);
    }
  }
  return tstNode;
}

// recursively traverse & print the ternary search tree in order
// O(N) where N is the number of nodes
void printTST(tstNode_t *root, char *buffer, int level) {
  if (!root) {
    return;
  }
  printTST(root->left, buffer, level);
  buffer[level] = root->data;

  if (root->isLeaf) {
    buffer[level + 1] = '\0';
    printf("%s\n", buffer);
  }

  printTST(root->mid, buffer, level + 1);

  printTST(root->right, buffer, level);
}


// check if ternary search tree contains given word
// average-case: O(logN) the height of the tree where N is the number of nodes
// worst-case: O(N) total skew tree
bool contain(tstNode_t *root, const char *word) {
  tstNode_t *node = getNode(root, word);

  if (!word || !*word || !node) {
    return false;
  }
  return true;
}

// free a node recursively
// time complexity: O(N) traverse the whole trie and free every node
void deleteTST(tstNode_t *tstNode) {
  if (!tstNode) {
    return;
  }

  if (!isLeafNode(tstNode)) {
    deleteTST(tstNode->left);
    deleteTST(tstNode->mid);
    deleteTST(tstNode->right);
  }

  free(tstNode);
}

// read a file containing words and insert words into the ternary trie
tstNode_t *createTSTFromFile(tstNode_t *root, const char *fileName) {
  FILE *file = fopen(fileName, "r");
  if (!file) {
    puts("Fails to open the file:");
    puts(fileName);
    return NULL;
  }

  char word[100]; // word length is limited within 100 chars

  while (fgets(word, sizeof(word), file)) {
    // truncate the tail \0 of a word
    word[strlen(word) - 1] = 0;
    root = insert(root, word);
  }

  fclose(file);
  return root;
}

// recursively search words with matching prefix and add them to completions list
// average-case: O(logN) the height of the tree where N is the number of nodes
// worst-case: O(N) total skew tree
void getCompletion(tstNode_t *root, char *prefix, slist_t *completions) {
  if (!root) {
    return;
  }

  if (root->isLeaf) {
    append(completions, prefix);
  }

  if (isLeafNode(root)) {
    return;
  }

  // declare a new char array to store prefix and root's data
  char *newPrefix = malloc(strlen(prefix) + 2);
  strcpy(newPrefix, prefix);
  strcat(newPrefix, &root->data);

  getCompletion(root->left, prefix, completions);
  getCompletion(root->mid, newPrefix, completions);
  getCompletion(root->right, prefix, completions);

  free(newPrefix);
}

// perform auto-complete, search given word within ternary trie and print them
void autoComplete(tstNode_t *root, char *word) {
  if (*word) {
    root = getNode(root, word);
  }

  slist_t *completions = createList();

  getCompletion(root, word, completions);
  printList(completions);
  deleteList(completions);
}