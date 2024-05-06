#include <stdio.h>

#define VERTICES 4

void createMatrix(int matrix[][VERTICES]){
  for (int i = 0; i < VERTICES; i++) {
    for (int j = 0; j < VERTICES; j++) {
      matrix[i][j] = 0;
    }
  }
}

void addEdge(int matrix[][VERTICES], int i,int j){
  matrix[i][j] = 1;
  matrix[j][i] = 1;
}

void printMatrix(int matrix[][VERTICES]){
  printf("   ");
  for (int i = 0; i < VERTICES; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i = 0; i < VERTICES; i++) {
    printf("%d: ", i);
    for (int j = 0; j < VERTICES; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {

  int matrix[VERTICES][VERTICES];
  createMatrix(matrix);
  addEdge(matrix, 0, 1);
  addEdge(matrix, 0, 2);
  addEdge(matrix, 1, 2);
  addEdge(matrix, 2, 0);
  addEdge(matrix, 2, 3);

  printMatrix(matrix);

  return 0;
}
