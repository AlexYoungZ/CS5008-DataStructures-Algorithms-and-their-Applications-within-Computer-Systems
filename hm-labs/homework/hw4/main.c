/***************************************************************************//**

  @file         main.c

  @author       Stephen Brennan with additional function

  @date         Thursday,  8 January 2015

  @brief        LSH (Libstephen SHell)

*******************************************************************************/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include "writeHistory.c"

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#define ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO)


/*
  Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_mkdir(char **args);
int lsh_cp(char **argv);
int lsh_history(char **argv);
int lsh_exclamHistoryNum(char **argv);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "mkdir",
    "cp",
    "history",
    "!"// !
};

int (*builtin_func[])(char **) = {
    &lsh_cd,
    &lsh_help,
    &lsh_exit,
    &lsh_mkdir,
    &lsh_cp,
    &lsh_history,
    &lsh_exclamHistoryNum// !
};

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/




/**
   @brief Builtin command: change directory.
   @param args List of args.  args[0] is "cd".  args[1] is the directory.
   @return Always returns 1, to continue executing.
 */
int lsh_cd(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    return 1;
  } else if (strcmp(args[1], "..") == 0) { // if given arg is ..
    chdir("..");
  } else if (chdir(args[1]) != 0) { // if given dir exists
    printf("directory %s doesn't exist\n", args[0]);
  }
  return 1; // return to shell
}

/**
   @brief Builtin command: mkdir.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
int lsh_mkdir(char **args) {
  int n = 1; // args[1] as input dir, args[0]=mkdir

  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"mkdir\"\n");
    return 1;
  }

  while (args[n] != NULL) {
    if (chdir(args[n]) == 0) {
      printf("directory %s already exist\n", args[n]);
      n++;
      chdir("..");
      continue;
    }

    if (chdir(args[n]) != 0) { // if not exist
      struct stat st = {0};
      if (stat(args[n], &st) == -1) {
        mkdir(args[n], ACCESSPERMS);
      }
      n++;

    }
  }
  return 1;
}

int lineCount = 0;

/**
   @brief Builtin command: history.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
int lsh_history(char **argv) { // get tokonize
  int lineNum = 0;

  FILE *file;
  char line[LSH_TOK_BUFSIZE];
  file = fopen("history.txt", "r");

  int c = fgetc(file);
  if (c == EOF) {
    printf("No past history command\n");
  } else { // read file and print each line
    while (fgets(line, LSH_TOK_BUFSIZE, file)) { // why 1 kdir
      lineNum++;
      lineCount++;
      printf("%d %s", lineNum, line);
    }
  }
  fclose(file);

  return 1;
}

/**
   @brief Builtin command: cp.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
int lsh_cp(char **argv) {
  char buffer[1024];
  int file[2];
  ssize_t fsize;

  if (argv[2] == NULL) {
    printf("lsh: expected argument to cp\n");
    return 1;
  }

  file[0] = open(argv[1], O_RDONLY);
  if (file[0] == -1) {
    printf("cannot open file %s with permission,", argv[1]);
    return 1;
  }

  file[1] = open(argv[2], O_WRONLY);
  if (file[1] == -1) {
    printf("cannot open file %s with permission,", argv[2]);
    close(file[0]);
    return 1;
  }

  while ((fsize = read(file[0], buffer, sizeof(buffer))) != 0) {
    write(file[1], buffer, fsize);
  }

  return 1;
}

/**
   @brief Builtin command: print help.
   @param args List of args.  Not examined.
   @return Always returns 1, to continue executing.
 */
int lsh_help(char **args) {
  int i;
  printf("Stephen Brennan's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

/**
   @brief Builtin command: exit.
   @param args List of args.  Not examined.
   @return Always returns 0, to terminate execution.
 */
int lsh_exit(char **args) {
  printf("See you next time\n");
  return 0;
}

/**
  @brief Launch a program and wait for it to terminate.
  @param args Null terminated list of arguments (including program).
  @return Always returns 1, to continue execution.
 */
int lsh_launch(char **args) {
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {

    // Child process
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("lsh");
  } else {
    // Parent process
    do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

/**
   @brief Execute shell built-in or launch program.
   @param args Null terminated list of arguments.
   @return 1 if the shell should continue running, 0 if it should terminate
 */
int lsh_execute(char **args) {
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return lsh_launch(args);
}

char *copy(const char src[], size_t srcLength, char dest[]) {
  for (int j = 0; j < srcLength; j++) {
    if (src[j] == '\n') {
      dest = (char *) malloc((j + 1) * sizeof(char));
    }
  }

  for (int i = 0; i < srcLength; i++) {
    if (src[i] == '\n') {
      dest[i] = '\0';
      return dest;
    }
    dest[i] = src[i];
  }
  return dest;
}
/**
   @brief Builtin command: perform history commands
   @param args List of args.  args[0] is "!".  args[1] is the index of history command.
   @return Always returns 1, to continue executing.
 */
int lsh_exclamHistoryNum(char **argv) { // c library
  char *index = argv[1];
  int indexNum = atoi(index);
  FILE *file;
  char line[10];
  char *command;

  file = fopen("history.txt", "r");
  int lineNumber = 1;

  if (indexNum > lineCount || indexNum < 0) {
    printf("the input index cannot match history command\n");
  } else {
    int c = fgetc(file);
    if (c == EOF) {
      printf("No past history command\n");
    } else { // read file and return index line command
      while (fgets(line, LSH_TOK_BUFSIZE, file) != NULL) { // why 1 kdir
        if (indexNum == lineNumber) {
          printf("%s", line);
          int srcLength = sizeof(line);
          command = copy(line, srcLength, command);
//          command = (char *) command;
          char **input = (char **) malloc(sizeof(command));
          input[0] = command;
//          printf("%s", input[0]);

          lsh_execute(input);
        }
        lineNumber++;
      }
    }

  }
  fclose(file);

  return 1;
}

/**
   @brief Read a line of input from stdin.
   @return The line from stdin.
 */
char *lsh_read_line(void) {
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  if (getline(&line, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);  // We received an EOF
    } else {
      perror("lsh: getline\n");
      exit(EXIT_FAILURE);
    }
  }
  return line;
}

/**
   @brief Split a line into tokens (very naively).
   @param line The line.
   @return Null-terminated array of tokens.
 */
char **lsh_split_line(char *line) {
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token, **tokens_backup;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens) {
        free(tokens_backup);
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

/**
   @brief Loop getting input and executing it.
 */
void lsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line); // write args into file
    writeHistory(args);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

/**
   @brief Main entry point.
   @param argc Argument count.
   @param argv Argument vector.
   @return status code
 */
int main(int argc, char **argv) {
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}

