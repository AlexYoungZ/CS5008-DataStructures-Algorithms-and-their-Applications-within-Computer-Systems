// Implement your part 1 solution here
// gcc vfork.c -o vfork
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Modify your paint function here
void paint(int workID) {
  printf("Artist %d is painting\n", workID);
}

int main(int argc, char **argv) {
  int *integers = malloc(sizeof(int) * 8000);

  int numberOfArtists = 8; // How many child processes do we want?

  pid_t pid;

  int i;

  // main loop where we fork new threads
  for (i = 0; i < numberOfArtists; i++) {
    // (1) Perform a fork
    pid = fork();

    // (2) Make only the child do some work (i.e. paint) and then terminate.
    if (pid == 0) {
      // make child paint
      int workID = getpid();
      paint(workID);
      // Then terminate/exit child
      exit(0);
    }
  }

  pid_t wpid;
  int status = 0;
  while ((wpid = wait(&status)) > 0) {}
  printf("parent is exiting(last artist out!)\n");

  free(integers);
  return 0;
}
