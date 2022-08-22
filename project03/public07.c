#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 7 (public07.c)
 *
 * Tests calling disassemble() on a program with an invalid value for
 * max_addr.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Mach_word program[]= {0x54c00000, 0x188c0000, 0x42801f40, 0x44d00000,
                        0x50c03e80, 0x48400fa0, 0x00000000};

  disassemble(program, 18432);

  printf("If this is the only thing printed by this test- without anything ");
  printf("at all before\nit- then it worked like a charm!\n");

  return 0;
}
