#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

typedef struct graph_node {
  int data;
  struct graph_node *next;
} graph_node_t;

typedef struct graph {
  int numVertices;
  bool *visited;
  graph_node_t **adjList; // 2D array
} graph_t;

graph_node_t *createNode(int val) {
  graph_node_t *newNode = malloc(sizeof(graph_node_t));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

graph_t *createGraph(int vertices) {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->numVertices = vertices;
  graph->adjList = malloc(vertices * sizeof(graph_node_t));
  graph->visited = malloc(vertices * sizeof(int));

  for (int i = 0; i < vertices; i++) {
    graph->adjList[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(graph_t *graph, int src, int dest) {
  // src to dest
  graph_node_t *newNode = createNode(dest);
  newNode->next = graph->adjList[src];
  graph->adjList[src] = newNode;

  // dest to src
//  newNode = createNode(src);
//  newNode->next = graph->adjList[dest];
//  graph->adjList[dest] = newNode;
}

void dfs(graph_t *graph, int vertex) {
  graph_node_t *adjList = graph->adjList[vertex];
  graph_node_t *temp = adjList;

  graph->visited[vertex] = 1;
  printf("%d -> ", vertex);

  while (temp != NULL) {
    int neighbor = temp->data;

    if (graph->visited[neighbor] == 0) {
      dfs(graph, neighbor);
    }
    temp = temp->next;
  }
}

void bfs(graph_t *graph, int vertex) {
  queue_t *queue = createQueue(graph->numVertices);
  graph->visited[vertex] = 1;
  enqueue(queue, vertex);

  while (!isEmpty(queue)) {
    int cur = dequeue(queue);
    printf("%d -> ", cur);

    graph_node_t *temp = graph->adjList[cur];

    while (temp) {
      int adjVertex = temp->data;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(queue, adjVertex);
      }
      temp = temp->next;
    }
  }
}

void reset(graph_t* graph){
  for (int i = 0; i < graph->numVertices; i++) {
    graph->visited[i] = false;
  }
}

void printGraph(graph_t *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    graph_node_t *temp = graph->adjList[i];
    if (temp != NULL) {
      printf("Adjacent list of vertex %d\n ", i);
    }
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Testing print adjacent list of graph
void unitTest1() {
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  printGraph(graph);
}

// Testing bfs traversal of graph
void unitTest2() {
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  printf("\nBFS start at vertex %d: \n", 1);
  bfs(graph, 1);
}

// Testing dfs traversal of graph
void unitTest3() {
  graph_t *graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  printf("\nDFS start at vertex %d: \n", 1);
  dfs(graph, 1);
}

int main() {
  unitTest1();
  unitTest2();
  unitTest3();
  return 0;
}
