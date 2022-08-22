#include <stdio.h>
#include "init.h"
#include "test-equal.h"

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

int main(void) {
  int arr1[10];
  int arr2[10]= {216, 216, 216, 216, 216, 216, 216, 216, 216, 216};

  init(arr1, 0, 3, 250);
  printf("%d\n", test_equal(arr1, arr2, 10));

  init(arr1, 0, 9, 216);
  printf("%d\n", test_equal(arr1, arr2, 10));

  return 0;
}
