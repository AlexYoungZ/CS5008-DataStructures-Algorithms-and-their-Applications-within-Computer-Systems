#include <stdio.h>
#include <time.h>
#include "floydWarshallNonRecursive.h"
#include "floydWarshallRecursive.h"

// test Non-recursive Floyd-Warshall with 4x4 matrix with positive edge
int unitTest1() {

  int graph[4][4] = {{0, 3, INF, 5},
                     {2, 0, INF, 4},
                     {INF, 1, 0, INF},
                     {INF, INF, 2, 0},
  };
  printf("Non-recursive Floyd-Warshall in 4x4 matrix with positive edge:\n");
  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Print the solution
  floydWarshallNonRecursive(graph);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time = %f seconds\n", time_taken);

  return 0;
}

// test Recursive Floyd-Warshall with 4x4 matrix with positive edge
int unitTest2() {
  int graph[4][4] = {{0, 3, INF, 5},
                     {2, 0, INF, 4},
                     {INF, 1, 0, INF},
                     {INF, INF, 2, 0},
  };
  printf("Recursive Floyd-Warshall in 4x4 matrix with positive edge:\n");

  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Print the solution
  printRecursive(graph);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time of recursive = %f seconds\n", time_taken);

  return 0;
}

// test Non-recursive Floyd-Warshall
// using 4x4 matrix with negative edge while without negative cycle
int unitTest3() {

  int graph[4][4] = {{0, INF, -2, INF},
                     {4, 0, 3, INF},
                     {INF, INF, 0, 2},
                     {INF, -1, INF, 0},
  };
  printf("Non-recursive Floyd-Warshall in 4x4 matrix with negative edge while without negative "
         "cycle:\n");
  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Print the solution
  floydWarshallNonRecursive(graph);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time = %f seconds\n", time_taken);

  return 0;
}

// test Recursive Floyd-Warshall
// using 4x4 matrix with negative edge while without negative cycle
int unitTest4() {
  int graph[4][4] = {{0, INF, -2, INF},
                     {4, 0, 3, INF},
                     {INF, INF, 0, 2},
                     {INF, -1, INF, 0},
  };
  printf("Recursive Floyd-Warshall in 4x4 matrix with negative edge while without negative "
         "cycle:\n");

  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Print the solution
  printRecursive(graph);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time of recursive = %f seconds\n", time_taken);

  return 0;
}

// test Non-recursive Floyd-Warshall
// using 4x4 matrix with negative edge and negative cycle
// for some nodes, it go to one extra traversal to the negative cycle to gain distance reduction
// benefit
int unitTest5() {

  int graph[4][4] = {{0, INF, -2, INF},
                     {4, 0, -3, INF},
                     {INF, INF, 0, 2},
                     {INF, -1, INF, 0},
  };
  printf("Non-recursive Floyd-Warshall in 4x4 matrix with negative edge and negative cycle:\n");
  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Print the solution
  floydWarshallNonRecursive(graph);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time = %f seconds\n", time_taken);

  return 0;
}

// test Recursive Floyd-Warshall
// using 4x4 matrix with negative edge and negative cycle
// clearly in this case the recursive version trapped in negative cycle and keep decreasing
// the distance of shortest path among nodes within the cycle
int unitTest6() {
  int graph[4][4] = {{0, INF, -2, INF},
                     {4, 0, -3, INF},
                     {INF, INF, 0, 2},
                     {INF, -1, INF, 0},
  };
  printf("Recursive Floyd-Warshall in 4x4 matrix with negative edge and negative cycle:\n");

  // Setup timers
  struct timespec begin, end;
  // Get the time before we start
  clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
  // Print the solution
  printRecursive(graph);
  // Get the time after we are done
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);

  double time_taken = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
      (end.tv_sec - begin.tv_sec);
  printf("Total time of recursive = %f seconds\n", time_taken);

  return 0;
}

int main() {
  unitTest1(),
      unitTest2(),
      unitTest3(),
      unitTest4();
  unitTest5(),
      unitTest6();

  return 0;
}
