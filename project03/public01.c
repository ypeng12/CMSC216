#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 1 (public01.c)
 *
 * Tests calling print_instruction() on a few types of instructions.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRUCTIONS 5

int main(void) {
  Mach_word instructions[NUM_INSTRUCTIONS]= {0x0858c000, 0x109d4000,
                                             0x1ce1c000, 0x21264000,
                                             0x316ac000};
  int i;

  for (i= 0; i < NUM_INSTRUCTIONS; i++) {
    print_instruction(instructions[i]);
    printf("\n");
  }

  return 0;
}
