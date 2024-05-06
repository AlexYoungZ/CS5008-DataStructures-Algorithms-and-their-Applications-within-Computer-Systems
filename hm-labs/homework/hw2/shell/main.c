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
#include <sys/stat.h>
#include <sys/fcntl.h>

/*
  Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_mkdir(char **args);
int lsh_cp(char **argv);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "mkdir",
    "cp"
};

int (*builtin_func[])(char **) = {
    &lsh_cd,
    &lsh_help,
    &lsh_exit,
    &lsh_mkdir,
    &lsh_cp
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

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
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
    args = lsh_split_line(line);
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

