#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>




int squareOfSum(int n) {
  int result = n*(n+1)/2;
  result *= result;
  return result;
}

int sumOfSquares(int n) {
  int result = n*(n+1)*(2*n+1)/6;
  return result;
}

int main() {
  int n = 10;
  printf("%i \n", squareOfSum(n)-sumOfSquares(n));
  return 0;
}