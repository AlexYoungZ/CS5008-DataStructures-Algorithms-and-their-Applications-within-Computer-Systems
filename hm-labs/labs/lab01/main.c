#include <stdio.h>
#include "math.h"

// compile file in this way including the link to math library
// gcc main.c -o main -lm
double power(double base, double n);

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int result;
  int i;

  for (i = 0; i < 10; ++i) {
    result = power(2, array[i]);
    printf("Power of %d base 2 is: %d\n", i+1 , result);
  }

}

double power(double base, double n) {
  return pow(base, n);
}

