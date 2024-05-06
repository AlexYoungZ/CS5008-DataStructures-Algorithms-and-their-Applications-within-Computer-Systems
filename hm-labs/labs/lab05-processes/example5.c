// Type in and try example5.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  char *myargv[16];// We can store up to 16 arguments.
  myargv[0] = "/bin/ls";
// Our first argument is the program we want to launch.
//  myargv[0] = "ls";
  // if argv is just ls, then execve will fail and continue execute
  //Child: Should never get here
  //This always prints last

  myargv[1] = "-F";// Any additional arguments (i.e. flags)  we want to make use of.
  myargv[2] = NULL;  // Terminate the argument list (similar to how we would terminate a
  // character string) (i.e. Set the last argument to NULL if we have no more flags.)
  if (fork() == 0) {
    // Executes command from child then terminates our process
    // Note: There are other 'exec' functions that may be helpful.
    execve(myargv[0], myargv, NULL);
    printf("Child: Should never get here\n");
    exit(1);
  } else {
    wait(NULL); // handy synchronization function again!
    printf("This always prints last\n");

  }
  return 0;
}

// it execute ls command under /bin directory
//CMakeLists.txt          example1.c              example3.c              example5.c
//README.md               example2*               example4*               example6.c
//cmake-build-debug/      example2.c              example4.c              myprogram.c
//example1*               example3*               example5*
//This always prints last