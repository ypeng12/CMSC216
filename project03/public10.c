#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 10 (public10.c)
 *
 * Tests calling is_valid() on a few instructions.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  assert(is_valid(0x52800960));
  assert(is_valid(0x2aaf0000));
  assert(is_valid(0x40400af0));
  assert(!is_valid(0xd88d0000));

  printf("The assertions worked like a charm!\n");

  return 0;
}
