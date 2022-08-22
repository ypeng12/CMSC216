#include <stdio.h>
#include "test-equal.h"

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

int main(void) {
  int arr1[]= {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9};
  int arr2[]= {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9};
  int arr3[]= {3, 1, 4, 5, 1, 9, 2, 6, 5, 3, 5, 9};

  printf("%d\n", test_equal(arr1, arr2, 12));
  printf("%d\n", test_equal(arr1, arr3, 12));

  return 0;
}
