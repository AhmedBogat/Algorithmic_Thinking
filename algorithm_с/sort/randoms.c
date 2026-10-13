#include <stdlib.h>
#include <stdio.h>
#include "sor.h"
#include "sor.c"

int random_int(int low, int high) {
  int i, j, r;
  i = RAND_MAX / (high - low + 1);
  i *= (high - low + 1);
  while ((j = rand()) >= i) {
    continue;
  }
  r = (j % (high - low + 1)) + low;
  if ((r < low) || (r > high)) {
    printf("Error: random integer %d out of range [%d,%d]\n",
           r, low, high);
  }
  return (r);
}

void random_permutation(int a[], int n) {
  for (int i = n; i > 1; i--) {
    swap(&a[i - 1], &a[random_int(0, i - 1)]);
  }
}
