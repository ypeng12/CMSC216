#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 12 (public12.c)
 *
 * Tests calling check_branches() on a program with all valid branches.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX_ADDR 36

int main(void) {
  Mach_word program[]= {0x48800064,   /*  0: li     R2 100   */
                        0x48c00064,   /*  4: li     R3 100   */
                        0x050c8000,   /*  8: add    R4 R3 R2 */
                        0x150c8000,   /*  c: rem    R4 R3 R2 */
                        0x3114c000,   /* 10: lt     R4 R5 R3 */
                        0x40800004,   /* 14: test   R2  4    */
                        0x40c00020,   /* 18: test   R3 32    */
                        0x4100000c,   /* 1c: test   R4 12    */
                        0x00000000};  /* 20: halt            */

  assert(check_branches(program, MAX_ADDR) == 1);

  printf("The assertion worked like a charm!\n");

  return 0;
}
