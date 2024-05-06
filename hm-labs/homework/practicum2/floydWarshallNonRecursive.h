#ifndef PRACTICUM2_FLOYD_WARSHALL_NON_RECURSIVE_H_
#define PRACTICUM2_FLOYD_WARSHALL_NON_RECURSIVE_H_

// non-recursive implementation of Floyd-Warshall algorithm to find shortest distances between every
// pair of vertices within weighted directed graph

#include <stdio.h>
#define Vertices 4
#define INF 999

void printMatrix(int dist[Vertices][Vertices]) {
  for (int i = 0; i < Vertices; i++) {
    for (int j = 0; j < Vertices; j++) {
      if (dist[i][j] == INF) {
        printf("%7s", "INF");
      } else {
        printf("%7d", dist[i][j]);
      }
    }
    printf("\n");
  }
}

void floydWarshallNonRecursive(int graph[Vertices][Vertices]) {
  int dist[Vertices][Vertices];

  // initialize distance matrix
  for (int i = 0; i < Vertices; i++) {
    for (int j = 0; j < Vertices; j++) {
      dist[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < Vertices; k++) {
    for (int i = 0; i < Vertices; i++) {
      for (int j = 0; j < Vertices; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  printMatrix(dist);
}

#endif
