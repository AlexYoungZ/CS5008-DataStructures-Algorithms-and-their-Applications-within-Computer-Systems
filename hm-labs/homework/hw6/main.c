// https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4)%N
#define RIGHT (phnum+1)%N

int state[N];
int phil[N] = {0, 1, 2, 3, 4};
sem_t mutex; // only one philosopher can pickup or put down
sem_t S[N]; // control behavior of each one

void test(int phnum) {
  if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
    state[phnum] = EATING; // the phnum is eating
    sleep(2);

    printf("Philosopher %d takes fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1);
    printf("Philosopher %d is Eating\n", phnum + 1);

    sem_post(&S[phnum]); // used during put down to inform left and right ones, unlock
  }
}

void takeFork(int phnum) {
  sem_wait(&mutex);

  state[phnum] = HUNGRY;

  printf("Philosopher %d is Hungry\n", phnum + 1);

  // check neighbors eating, if not, start eating.
  test(phnum);

  sem_post(&mutex);

  // if cannot eat then wait the signal
  sem_wait(&S[phnum]);

  sleep(1);
}

void putFork(int phnum) {
  sem_wait(&mutex);

  state[phnum] = THINKING;

  printf("Philosopher %d putting fork %d and %d down\n",
         phnum + 1, LEFT + 1, phnum + 1);
  printf("Philosopher %d is thinking\n", phnum + 1);

  test(LEFT);
  test(RIGHT);

  sem_post(&mutex);
}

void *philospher(void *num) {
  while (1) {
    int *i = num;
    takeFork(*i);
    sleep(0);
    putFork(*i);
  }
}

int main() {
  int i;
  pthread_t thread_id[N];

  sem_init(&mutex, 0, 1);

  for (int i = 0; i < N; i++) {
    sem_init(&S[i], 0, 0);
  }

  for (int i = 0; i < N; i++) {
    pthread_create(&thread_id[i], NULL, philospher, &phil[i]);
  }

  for (int i = 0; i < N; i++) {
    pthread_join(thread_id[i], NULL);
  }
}
//Philosopher 1 is Hungry
//Philosopher 2 is Hungry
//Philosopher 3 is Hungry
//Philosopher 4 is Hungry
//Philosopher 5 is Hungry
//Philosopher 4 putting fork 3 and 4 down
//Philosopher 4 is thinking
//Philosopher 4 is Hungry
//Philosopher 2 putting fork 1 and 2 down
//Philosopher 2 is thinking
//Philosopher 2 is Hungry
//Philosopher 5 putting fork 4 and 5 down
//Philosopher 5 is thinking
//Philosopher 5 is Hungry
//Philosopher 3 takes fork 2 and 3
//Philosopher 3 is Eating
//Philosopher 1 takes fork 5 and 1
//Philosopher 1 is Eating
//Philosopher 4 putting fork 3 and 4 down
//Philosopher 4 is thinking
//Philosopher 4 is Hungry
//Philosopher 5 putting fork 4 and 5 down
//Philosopher 5 is thinking
//Philosopher 2 putting fork 1 and 2 down
//Philosopher 2 is thinking
//Philosopher 2 is Hungry
//Philosopher 5 is Hungry
//Philosopher 1 putting fork 5 and 1 down
//Philosopher 1 is thinking
//Philosopher 3 putting fork 2 and 3 down
//Philosopher 3 is thinking
//Philosopher 4 putting fork 3 and 4 down
//Philosopher 4 is thinking
//Philosopher 4 is Hungry
//Philosopher 2 putting fork 1 and 2 down
//Philosopher 2 is thinking
//Philosopher 2 is Hungry
//Philosopher 5 putting fork 4 and 5 down
//Philosopher 5 is thinking
//Philosopher 5 is Hungry
//Philosopher 5 putting fork 4 and 5 down
//Philosopher 5 is thinking
//Philosopher 5 is Hungry
