#include <stdio.h>
#include "len.h"

#define put(X) \
        _Generic((X), \
            int: integer,\
            double : doubler)((X))

void integer(int i) { printf("%x\t", i); }

void doubler(double x) { printf("%g\t", x + 1.2); }

char *upper(char *s) {
  int i;
  for (; i < len(s); ++i) {
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] -= 32;
  }
  return s;
}
int len(char *s) {
  int i = 0;
  while (*s++)
    i++;
  return i;
}

char *summa(char *s1, int n, char *s2) {
  if (s1 == 0 || s2 == 0)
    return 0;
  if (n < len(s1) + len(s2) + 1)
    return s1;

  int i = 0;
  for (; i <= len(s2); i++)
    s1[i + len(s1)] = s2[i];
  return s1;
}

void minMax(int *d, int n, int *pa, int *pd) {
  int i, min, max;
  min = max = *d;
  for (i = 1; i < n; i++) {
    if (d[i] > max)
      max = d[i];
    if (d[i] < min)
      min = d[i];
  }

  *pa = min;
  *pd = max;

}

