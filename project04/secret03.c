#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 3 (secret03.c)
 *
 * Tests that invalid values in fields that are not actually used by
 * instructions do not affect instruction validity.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRUCTIONS 8

int main(void) {
  Mach_word instructions[NUM_INSTRUCTIONS]= {0x240bc000, 0x407b8000,
                                             0x448f8000, 0x517fc258,
                                             0x55bfc000, 0x59ffc000,
                                             0x03bf8000, 0xffffffff};
  int i;


  for (i= 0; i < NUM_INSTRUCTIONS - 1; i++)
    assert(is_valid(instructions[i]));

  /* the very last instruction is the only invalid one */
  assert(!is_valid(instructions[NUM_INSTRUCTIONS - 1]));

  printf("All assertions succeeded convincingly!\n");

  return 0;
}
