#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 9 (public09.c)
 *
 * Tests that disassemble() stops printing instructions when it sees an
 * instruction in the program that tries to modify the special program
 * counter register R13.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX_ADDR 24

int main(void) {
  Mach_word program[]= {0x258c0000, 0x40802710, 0x44480000, 0x1c498000,
                        0x50403034, 0x4f403034, 0x00000000};

  assert(disassemble(program, MAX_ADDR) == 0);

  printf("The assertion worked like a charm!\n");

  return 0;
}
