// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 64

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int colors[64][64 * 3];

void *paint(void *arg) {
//  pthread_mutex_lock(&mutex);
  int x = (int) arg;
//  printf("%d\n", x);
  for (int i = 0; i < 191; i++) {
    colors[x][i] = x * 2;
  }
//  pthread_mutex_unlock(&mutex);
  return NULL;
}

void save() {
  // Write out the PPM file
  // If you are looking at this solution, it could
  //be better laid out in a 'save function'
  FILE *fp;
  fp = fopen("./paint.ppm", "w+");
  fputs("P3\n", fp);
  fputs("64 64\n", fp);
  fputs("255\n", fp);
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64 * 3; j++) {
      fprintf(fp, "%d", colors[i][j]);
      fputs(" ", fp);
    }
    fputs("\n", fp);
  }
  fclose(fp);
}

int main() {
  pthread_t threadIDs[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threadIDs[i], NULL, paint, (void *) i);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threadIDs[i], NULL);
  }

  save();

  return 0;
}