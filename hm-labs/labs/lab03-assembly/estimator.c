// Implement your cycle count tool here.
//
// Compile with: gcc -g -Wall args.c -o args
// Try running with:
// - ./args
// - ./args somefile.c
// - ./args argv1 argv2
// The parameters to the main function are read in
// when you execute your program on the terminal.
// argc: is the argument count
// argv: is a 'variable' number of arguments provided
//
// This program shows how to iterate through all of the arguments
//  printf("argc is the argument count: %d\n", argc);
//  // This loop will print out all of the arguments
//  for (int i = 0; i < argc; i++) {
//    printf("argv[%d] is %s\n", i, argv[i]);
// Then you can use the argv's as needed.
// example:
// If argv[1] is suppose to be a particular (like the filename),
// you can make use of it.
// So your next step would be to use FILE* input = fopen(argv[1],"r");
// Then read every line in that file, and 'parse' the first few characters
//# Build an executable using the following:
//#
//# clang barebones.s -o barebones  # clang is another compiler like gcc
//#
#include <stdio.h>
#include <string.h>


typedef struct instruction {
  char word[10];
  int count;
} instruct_t;

int wordCount(char *str, char *word) {
  int count;
  int strLen, wordLen;
  int status;

  strLen = strlen(str);
  wordLen = strlen(word);

  count = 0;

  for (int i = 0; i <= strLen - wordLen; i++) {
    status = 1;
    for (int j = 0; j < wordLen; j++) {
      if (str[i + j] != word[j]) {
        status = 0;
        break;
      }
    }

    if (status == 1) {
      count++;
    }
  }
  return count;
}

int main(int argc, char **argv) {
  int instruct_num = 0;
  int cycle;
  instruct_t
      arr_word[10] = {
      {"add", 0},
      {"sub", 0},
      {"mul", 0},
      {"div", 0},
      {"mov", 0},
      {"lea", 0},
      {"push", 0},
      {"pop", 0},
      {"ret", 0}}; // later, maybe regex

  FILE *fp = fopen(argv[1], "r");
  char string[100000];

  if (fp == NULL) {
    printf("cannot open the file %s\n", argv[1]);
  }
  int i;
  char ch;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\t' || ch == '\0' || ch == '\n') {
      continue;
    }
    fflush(stdin);
    string[i++] = ch;
  }

//  printf("The string is %s\n", string);

  for (int i = 0; i < 9; i++) {
    arr_word[i].count = wordCount(string, arr_word[i].word);
  }

//  printf("the mov count is: %d\n", arr_word[4].count);

  cycle =
      arr_word[0].count * 1 +
          arr_word[1].count * 1 +
          arr_word[2].count * 3 +
          arr_word[3].count * 24 +
          arr_word[4].count * 1 +
          arr_word[5].count * 3 +
          arr_word[6].count * 1 +
          arr_word[7].count * 1 +
          arr_word[8].count * 1;

  for (int i = 0; i < 9; i++) {
    instruct_num += arr_word[i].count;
  }

  printf("Total Instructions = %d\n", instruct_num);
  printf("Total Cycles = %d\n", cycle);

  fclose(fp);
  return 0;
}



