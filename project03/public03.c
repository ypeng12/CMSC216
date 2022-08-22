#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 3 (public03.c)
 *
 * Tests calling print_instruction() on an invalid instruction.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRUCTIONS 7

int main(void) {
  print_instruction(0xffffffff);

  printf("If this is the only thing printed by this test- without anything ");
  printf("at all before\nit- then it worked like a charm!\n");

  return 0;
}
