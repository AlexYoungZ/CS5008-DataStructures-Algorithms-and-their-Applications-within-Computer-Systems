#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "minheap.h"
#include "graph.h"
#include <limits.h>

// O(E*logV)
void dijkstra(graph_t* graph, int src){
  int numVertices = graph->numVertices;
  int distance[numVertices];

  minHeap_t *minHeap = createMinHeap(numVertices);

  for (int i = 0; i < numVertices; i++) {
    distance[i] = INT_MAX;
    minHeap->array[i] = createHeapNode(i, distance[i]);
    minHeap->pos[i] = i;
  }

  // src dist is 0
  minHeap->array[src] = createHeapNode(src, distance[src]);
  minHeap->pos[src] = src;
  minHeap->size = numVertices;
  distance[src] = 0;
  decreaseKey(minHeap, src, distance[src]);

  // loop to include non-visited nodes in the minHeap
  while (!isEmptyHeap(minHeap)) {
    // extract node with min dist, num of vertices operations
    heapNode_t *heapNode = extractMin(minHeap);
    int uVal = heapNode->data;
    // traverse adjacent neighbors and update their dist
    graph_node_t *neighbor = graph->adjList[uVal].head;
    while (neighbor != NULL) {
      int vVal = neighbor->dest;
      // if shortest distance is not finalized and distance to node is less
      if ((vertexExist(minHeap, vVal)) && (distance[uVal] != INT_MAX) &&
          (neighbor->weight + distance[uVal] < distance[vVal])) {
        distance[vVal] = distance[uVal] + neighbor->weight;
        // update distance in min-heap, num of edges operations
        decreaseKey(minHeap, vVal, distance[vVal]);
      }
      neighbor = neighbor->next;
    }
  }
  printResult(distance, numVertices);
}
#endif