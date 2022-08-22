#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 2 (public02.c)
 *
 * Tests calling print_instruction() on some other types of instructions.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRUCTIONS 7

int main(void) {
  Mach_word instructions[NUM_INSTRUCTIONS]= {0x54c00000, 0x188c0000,
                                             0x42801f40, 0x44d00000,
                                             0x50c03e80, 0x48400fa0,
                                             0x00000000};
  int i;

  for (i= 0; i < NUM_INSTRUCTIONS; i++) {
    print_instruction(instructions[i]);
    printf("\n");
  }

  return 0;
}
