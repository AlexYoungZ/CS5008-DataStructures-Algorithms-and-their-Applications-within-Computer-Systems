#include <stdio.h>

int writeHistory(char **args) {
  FILE *file;


  // open to write
  file = fopen("/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw4/history.txt", "a");
  if (!file) {
    printf("File cannot open\n");
    getchar();
    return 1;
  }

  int writeStatus = fprintf(file, "%s\n", *args); // only the first word

  if (writeStatus < 0) {
    perror("cannot write into file");
  }

  // close
  fclose(file);

  return 1;
}