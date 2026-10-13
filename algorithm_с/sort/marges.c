#include "sor.h"
#include "../linklist/queue.h"

void marge(item_type s[], int low, int middle, int high) {
  int i;
  queue buffer1, buffer2;
  init_queue(&buffer1);
  init_queue(&buffer2);

  for (i = low; i <= middle; i++)
    enqueue(&buffer1, s[i]);
  for (i = middle + 1; i <= high; i++)
    enqueue(&buffer2, s[i]);
  i = low;
  while (!(empty_queue(&buffer1) || empty_queue(&buffer2))) {
    if (headq(&buffer1) <= headq(&buffer2)) {
      s[i++] = dequeue(&buffer1);
    } else {
      s[i++] = dequeue(&buffer2);

    }
  }
  while (!empty_queue(&buffer1)) {
    s[i++] = dequeue(&buffer1);
  }
  while (!empty_queue(&buffer2)) {
    s[i++] = dequeue(&buffer2);
  }

}

void marge_sort(item_type s[], int low, int high) {
  int middle;
  if (low + high) {
    middle = (low + high) / 2;
    marge_sort(s, low, middle);
    marge_sort(s, middle + 1, high);

    marge(s, low, middle, high);
  }
}