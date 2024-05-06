#include "graph.h"
#include "dijkstra.h"
#include "prim.h"

// Testing dijkstra
int unitTest1() {
  graph_t * graph = createGraph(9);
  addEdge(graph, 0, 1, 3);
  addEdge(graph, 1, 2, 5);
  addEdge(graph, 2, 3, 6);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 4, 8);
  addEdge(graph, 3, 5, 10);
  addEdge(graph, 4, 5, 14);
  addEdge(graph, 5, 6, 2);
  addEdge(graph, 6, 7, 1);
  addEdge(graph, 6, 8, 5);
  addEdge(graph, 7, 8, 8);

  dijkstra(graph, 0);

  return 0;
}

// Testing prim
int unitTest2() {
  graph_t * graph = createGraph(9);
  addEdge(graph, 0, 1, 3);
  addEdge(graph, 1, 2, 5);
  addEdge(graph, 2, 3, 6);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 4, 8);
  addEdge(graph, 3, 5, 10);
  addEdge(graph, 4, 5, 14);
  addEdge(graph, 5, 6, 2);
  addEdge(graph, 6, 7, 1);
  addEdge(graph, 6, 8, 5);
  addEdge(graph, 7, 8, 8);

  primMST(graph);

  return 0;
}




int main() {
  printf("Dijkstra: \n");
  unitTest1();
  printf("Prim MST: \n");
  unitTest2();
}


