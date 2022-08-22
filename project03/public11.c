#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 11 (public11.c)
 *
 * Tests calling is_valid() on a few more instructions.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  assert(is_valid(0x48800064));
  assert(is_valid(0x48c00064));
  assert(is_valid(0x050c8000));
  assert(!is_valid(0x17cc8000));

  printf("The assertions worked like a charm!\n");

  return 0;
}
