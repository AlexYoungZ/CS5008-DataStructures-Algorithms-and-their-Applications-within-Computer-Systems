#ifndef PRACTICUM2_FLOYD_WARSHALL_RECURSIVE_H_
#define PRACTICUM2_FLOYD_WARSHALL_RECURSIVE_H_
// recursive implementation of Floyd-Warshall algorithm to find shortest distances between every
// pair of vertices within weighted directed graph

#include <stdio.h>
#include <stdlib.h>

#define Vertices 4
#define INF 999

int min(int x, int y) {
  return (x < y) ? x : y;
}

int floydWarshallRecursive(int graph[Vertices][Vertices], int k, int i, int j) {
  int distIJ, distIKJ;
  if (k < 0) {
    return graph[i][j];
  } else {
    distIJ = floydWarshallRecursive(graph, k - 1, i, j);
    distIKJ = floydWarshallRecursive(graph, k - 1, i, k)
        + floydWarshallRecursive(graph, k - 1, k, j);
  }
  return min(distIJ, distIKJ);
}

void printRecursive(int graph[Vertices][Vertices]) {
  for (int i = 0; i < Vertices; i++) {
    for (int j = 0; j < Vertices; j++) {
      graph[i][j] = floydWarshallRecursive(graph, Vertices - 1, i, j);
    }
  }
  printMatrix(graph);
}

#endif
