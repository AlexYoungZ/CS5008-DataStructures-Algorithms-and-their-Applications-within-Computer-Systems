#include <stdio.h>


void pascal(int n){
  int table[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == j || j == 0) {
        table[i][j] = 1;
      } else {
        table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
      }
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n = 5;
  pascal(5);
  return 0;
}
