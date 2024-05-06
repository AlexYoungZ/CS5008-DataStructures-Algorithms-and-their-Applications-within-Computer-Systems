// Type in and try example1.c
#include <stdio.h>
#include <sys/types.h> // Includes some new data types (e.g. pid_t)
#include <unistd.h> // This is a new library that includes various unix system cal ls.
int main() {
// Variable to store the process id
  pid_t pid;
// Variable 'x' allocated on the stack
  int x = 1;
// fork returns a process id (we can distinguish processes by this value) // 0 is returned in the child process
// >0 is the process id of the child received by the parent
  pid = fork();
  if (pid == 0) {
    printf("child: x=%d\n", ++x); // ++x changes the value of x before using it (2)
    return 0;
  }
// Parent process executing
  printf("parent: x=%d\n", --x); // --x change the value of x before using it (1)
  return 0;
}
//parent: x=0
//child: x=2