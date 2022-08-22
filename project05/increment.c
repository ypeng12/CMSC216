#include "increment.h"

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

void increment(int a[], int size) {
  size--;
  while (size >= 0) {
    a[size]++;
    size--;
  }
}
