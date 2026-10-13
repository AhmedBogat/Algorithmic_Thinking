#include <string.h>
#include "findmatch.h"

int findmatch(char *p, char *t) {
  int i, j;
  int plen, tlen;

  plen = strlen(p);
  tlen = strlen(p);

  for (i = 0; i <= (tlen - plen); i = i + 1) {
    j = 0;
    while ((j < plen) && (t[i + j] == p[j])) {
      j = j + 1;
    }
    if (j == plen) {
      return (i);
    }
  }
  return (-1);
}