#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph_node {
  int dest;
  int weight;
  struct graph_node *next;
} graph_node_t;

typedef struct adjList {
  struct graph_node *head;
} adjList_t;

typedef struct graph {
  int numVertices;
  bool *visited;
  struct adjList *adjList;
} graph_t;

graph_node_t *createNode(int dest, int weight) {
  graph_node_t *newNode = malloc(sizeof(graph_node_t));
  newNode->dest = dest;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

graph_t *createGraph(int vertices) {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->numVertices = vertices;
  graph->adjList = (adjList_t *) malloc(vertices * sizeof(adjList_t));
  graph->visited = malloc(vertices * sizeof(int));

  for (int i = 0; i < vertices; ++i) {
    graph->adjList[i].head = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(graph_t *graph, int src, int dest, int weight) {
  // src to dest and node is added at front
  graph_node_t *newNode = createNode(dest, weight);
  newNode->next = graph->adjList[src].head;
  graph->adjList[src].head = newNode;

  // dest to src
//  newNode = createNode(src, weight);
//  newNode->next = graph->adjList[dest].head;
//  graph->adjList[dest].head = newNode;
}

#endif