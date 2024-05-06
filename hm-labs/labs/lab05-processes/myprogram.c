// Take a look at some of the previous examples to create your own program!
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t pid;
  pid = fork();
  char *argv1[16];
  argv1[0] = "/bin/ls"; // Our first argument is the program we want to launch.
  argv1[1] = "-F";
  argv1[2] = NULL;

//  char *argv2[] = {"echo \"testing\"", NULL};

  char argv2[16] = "echo \"testing\"";

  char argv3[16] = "nl example1.c";


  //  char *argv3[] = {"nl", "example1.c", NULL};

  if (pid == 0) {
    execve(argv1[0], argv1, NULL);
    exit(1);
  } else  {
    wait(NULL);
    printf("echo testing: \n");
//    execv("./", argv2);
    system(argv2);
//    exit(1);
  }
  printf("nl command: \n");
  system(argv3);
  printf("\n");
  printf("All three commands done\n");
  return 0;
}

