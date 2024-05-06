// Type in and try example2.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
// Variable to store the process id
  pid_t pid;
// Variable 'x' allocated on the stack
  int x = 1;
// fork returns a process id (we can distinguish processes by this value)
// 0 is returned in the child process
// >0 is the process id of the child received by the parent
  pid = fork();

  if (pid == 0) {
    printf("Terminating Child, PID= x=%d\n", getpid());
    exit(0);
  } else {
// Run the parent
    printf("Running parent forever(pretend I am a server): pid=%d\n", getpid());
    while (1) {} // run the parent forever
  }
  return 0;
}

//Zombie Process
//Running parent forever(pretend I am a server): pid=38543
//Terminating Child, PID= x=38544 why not first show
