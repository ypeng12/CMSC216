#include <stdio.h>
#include "init.h"
#include "increment.h"
#include "add-elements.h"

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

int main(void) {
  int arr[10];

  init(arr, 0, 9, 2);
  printf("%d\n", add_elements(arr, 10));

  increment(arr, 10);
  printf("%d\n", add_elements(arr, 10));

  return 0;
}
