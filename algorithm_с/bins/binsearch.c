#include "../sort/item.h"

int bins(item_type s[], item_type key, int low, int high) {
  int middle;
  if (low > high) {
    return (-1);
  }

  middle = (low + high) / 2;
  if (s[middle] == key) {
    return (bins(s, key, low, middle - 1));
  } else {
    return (bins(s, key, middle + 1, high));
  }

}