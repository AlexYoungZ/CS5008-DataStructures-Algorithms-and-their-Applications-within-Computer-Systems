#include <stdio.h>
#include "ternarySearchTree.h"

int main() {
  char command;
  char inputWord[20];
  tstNode_t *root = (tstNode_t *) NULL;
  root = createTSTFromFile(root, "dictionary.txt");

  while (true) {
    puts("Press w to enter a prefix to complete or q to quit");
    command = getchar();

    if (command == 'w') {
      puts("Enter a word to find its completions");
      scanf("%s", inputWord);
      puts("The auto-completed words are: ");
      autoComplete(root, inputWord);
    } else if (command == 'q') {
      break;
    }
    fseek(stdin, 0, SEEK_END); // clear input buffer
  }
  deleteTST(root);
}