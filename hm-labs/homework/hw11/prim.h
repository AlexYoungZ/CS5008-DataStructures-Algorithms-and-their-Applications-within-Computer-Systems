#ifndef PRIM_H
#define PRIM_H

#include "graph.h"
#include "minheap.h"
#include <limits.h>

void primMST(graph_t *graph) {
  int V = graph->numVertices;
  int parent[V];
  int key[V];

  minHeap_t *minHeap = createMinHeap(V);

  // initialize minHeap
  for (int v = 1; v < V; ++v) { // except src
    parent[v] = -1;
    key[v] = INT_MAX;
    minHeap->array[v] = createHeapNode(v, key[v]);
    minHeap->pos[v] = v;
  }

// first vertex to extract
  key[0] = 0;
  minHeap->array[0] = createHeapNode(0, key[0]);
  minHeap->pos[0] = 0;

  minHeap->size = V;

// while min-heap still contains nodes not within MST
  while (!isEmptyHeap(minHeap)) {
    // extract node with min key
    heapNode_t *minHeapNode = extractMin(minHeap);
    int u = minHeapNode->data;

    // visit neighbor and update their value
    graph_node_t *temp = graph->adjList[u].head;
    while (temp != NULL) {
      int v = temp->dest;

      // If v is not yet included in MST and weight of u-v is
      // less than key value of v, then update key value and
      // parent of v
      if (vertexExist(minHeap, v) && temp->weight < key[v]) {
        key[v] = temp->weight;
        parent[v] = u;
        decreaseKey(minHeap, v, key[v]);
      }
      temp = temp->next;
    }
  }

  printMST(parent, V);
}

#endif
