#include <stdio.h>
#include "graph.h"

// Testing graph is reachable
int unitTest1() {
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 5, 5);

  printGraph(graph);
  if (graph_is_reachable(graph, 0, 4)) {
    printf("graph is reachable\n");
    return 1;
  } else {
    return 0;
  }
}

// Testing graph is not reachable
int unitTest2() {
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 5, 4);

  printGraph(graph);

  if (graph_is_reachable(graph, 0, 5) == 0) {
    printf("graph is not reachable\n");
    return 1;
  }
  return 0;
}

// Testing graph has cycle
int unitTest3() {
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 0);

  printGraph(graph);
  if (graph_has_cycle(graph)) {
    printf("graph has cycle\n");
    return 1;
  }
  return 0;
}

// Testing graph has no cycle
int unitTest4() {
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 5);
  printGraph(graph);

  if (graph_has_cycle(graph) == 0) {
    printf("graph has no cycle\n");
    return 1;
  } else {
    return 0;
  }
}

// Testing print graph path
int unitTest5() {
  sllstack_t *sllstack = newStack();
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 5, 5);

  printGraph(graph);

  return graph_print_path(graph, 0, 4, sllstack);
}

// Testing print graph path when no path exists
int unitTest6() {
  sllstack_t *sllstack = newStack();
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 5, 5);
  printGraph(graph);

  if (graph_print_path(graph, 4, 1, sllstack) == 0) {
    printf("graph has no valid path connecting two nodes\n");
    return 1;
  }
  return -1;
}

int (*unitTests[])(int) ={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    NULL
};

int main() {
  unsigned int testsPassed = 0;
  // List of Unit Tests to test your data structure
  int counter = 0;
  while (unitTests[counter] != NULL) {
    printf("========unitTest %d========\n", counter + 1);
    if (1 == unitTests[counter](1)) {
      printf("passed test %d\n", counter + 1);
      testsPassed++;
    } else {
      printf("failed test %d, missing functionality, or incorrect test\n", counter + 1);
    }
    counter++;
  }

  printf("%d of %d tests passed\n", testsPassed, counter);

  return 0;
}

