#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  // parent - child1, child2 - grandchild1
  pid_t pid1 = fork();
  pid_t pid2 = fork();

  char *argv1[16];
  argv1[0] = "/bin/ls";
  argv1[1] = "-F";
  argv1[2] = NULL;

  char *argv2[16];
  argv2[0] = "/bin/echo";
  argv2[1] = "\"testing\"";
  argv2[2] = NULL;

  char argv3[16] = "nl example1.c";

  if (pid1 > 0 && pid2 > 0) { // parent
    wait(NULL);
    wait(NULL);
    printf("All three commands done\n");
    return 0;
  } else if (pid1 == 0 && pid2 > 0) { // child1
    sleep(2);
    wait(NULL);
    system(argv3);
  } else if (pid1 > 0 && pid2 == 0) { // child2
    sleep(1);
    execve(argv2[0], argv2, NULL);
    printf("\n");
  } else { // grandchild
    execve(argv1[0], argv1, NULL);
  }

}


