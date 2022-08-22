#include "init.h"

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else. */

void init(int arr[], int from, int to, int value) {
  int i;

  for (i= from; i <= to; i++)
    arr[i]= value;
}
