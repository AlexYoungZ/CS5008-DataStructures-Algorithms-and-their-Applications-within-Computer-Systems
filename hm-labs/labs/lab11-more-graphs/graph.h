#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "stack.h"

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

  while (!isEmptyQueue(queue)) {
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

void reset(graph_t *graph) {
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

// returns 1 if we can reach the destination from source
// returns 0 if it is not reachable
// returns -1 if the graph is NULL (using BFS)
int graph_is_reachable(graph_t *g, int source, int dest) {

  if (g == NULL) {
    return -1;
  }

  graph_node_t *tempNode;
  queue_t *queue = createQueue(g->numVertices);
  g->visited[source] = 1;
  enqueue(queue, source);

  while (!isEmptyQueue(queue)) {
    int cur = dequeue(queue);

    tempNode = g->adjList[cur];

    while (tempNode != NULL) {

      if (g->visited[tempNode->data] == 0) {
        g->visited[tempNode->data] = 1;
        enqueue(queue, tempNode->data);
      }

      if (tempNode->data == dest) {
        return 1;
      }
      tempNode = tempNode->next;
    }
  }
  return 0;
}

// returns 1 if there is a cycle in the graph
// returns 0 if no cycles exist in the graph
// returns -1 if the graph is NULL
// You may use either BFS or DFS to complete this task.
int graph_has_cycle(graph_t *g) {
  if (g == NULL) {
    return -1;
  }

  int vertex = g->adjList[0][0].data;

  queue_t *queue = createQueue(g->numVertices);
  g->visited[vertex] = 1;
  enqueue(queue, vertex);

  while (!isEmptyQueue(queue)) {
    int cur = dequeue(queue);

    graph_node_t *temp = g->adjList[cur];

    while (temp) {
      int adjVertex = temp->data;

      if (g->visited[adjVertex] == 0) {
        g->visited[adjVertex] = 1;
        enqueue(queue, adjVertex);
      }
      temp = temp->next;
      if (temp != NULL) {
        if (g->visited[temp->data] == 1) {
          return 1;
        }
      }
    }
  }

  // check for separate component
  for (int i = 0; i < g->numVertices; i++) {
    if (g->visited[i] == 0) {
      g->visited[i] = 1;
      enqueue(queue, g->adjList[i]->data);

      while (!isEmptyQueue(queue)) {
        int cur = dequeue(queue);

        graph_node_t *temp = g->adjList[cur];

        while (temp) {
          int adjVertex = temp->data;

          if (g->visited[adjVertex] == 0) {
            g->visited[adjVertex] = 1;
            enqueue(queue, adjVertex);
          }
          temp = temp->next;

          if (temp != NULL) {
            if (g->visited[temp->data] == 1) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

// prints any path from source to destination if there
// exists a path from the source to the destination.
// Note: Consider using one of the other functions to help you
//       determine if a path exists first
// (Choose either BFS or DFS, typically DFS is much simpler)
//
// Returns 1 if there is a path from source to destination
// Returns 0 if there is not a path from a source to destination
// Returns -1 if the graph is NULL
int graph_print_path(graph_t *g, int source, int dest, sllstack_t *sllstack) {
  if (g == NULL) {
    return -1;
  }

  graph_node_t *temp;
  push(sllstack, source);
  g->visited[source] = 1;

  while (!isEmptyStack(sllstack)) {
    temp = g->adjList[peek(sllstack)];

    while (temp != NULL) {
      if (g->visited[temp->data] == 0) {
        push(sllstack, temp->data);
      }

      if (temp->data == dest) {
        while (!isEmptyStack(sllstack)) {
          printf("%d <- ", pop(sllstack));
        }
        return 1;
      }
      temp = temp->next;
    }
    pop(sllstack);
  }
  return 0;
}