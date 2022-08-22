#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 13 (public13.c)
 *
 * Tests calling check_branches() on a program with an invalid branch.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX_ADDR 16

int main(void) {
  Mach_word program[]= {0x40c00007,   /*  0: test  R3 7     */
                        0x48800064,   /*  4: li    R2 100   */
                        0x48c00064,   /*  8: add   R4 R3 R2 */
                        0x00000000};  /*  c: halt           */

  /* the instruction at address 0 is invalid */
  assert(check_branches(program, MAX_ADDR) == 0);
  printf("The assertion worked like a charm!\n");

  return 0;
}
