#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 6 (public06.c)
 *
 * Tests calling disassemble() on a program with some other types of valid
 * instructions.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX_ADDR 24

int main(void) {
  Mach_word program[]= {0x54c00000, 0x188c0000, 0x42801f40, 0x44d00000,
                        0x50c03e80, 0x48400fa0, 0x00000000};

  disassemble(program, MAX_ADDR);

  return 0;
}
