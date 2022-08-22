#include "test-equal.h"

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

int test_equal(int a[], int b[], int size) {
  int same= 1, i= 0;

  while (i < size && same)
    if (a[i] != b[i])
      same= 0;
    else i++;

  return same;
}

