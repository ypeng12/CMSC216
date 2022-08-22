#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 8 (secret08.c)
 *
 * Tests calling run_program() with a Nelovo program that has invalid
 * instructions with incorrect register values.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRS 6

int main(void) {
  Nelovo nelovo;
  /* program1 has several instruction with invalid register values, while
     program2 is valid */
  Mach_word program1[NUM_WORDS]= {0x4a00002c, 0x4a40002c, 0x17a00000,
                                  0x327c0000, 0x36080000, 0x00000000};
  Mach_word program2[NUM_WORDS]= {0x48c0000b, 0x49000016, 0x49400021,
                                  0x058d0000, 0x0dd14000, 0x00000000};
  unsigned short num_instr= 0, invalid_instr_addr= 0;

  load_program(&nelovo, program1, NUM_INSTRS);
  assert(run_program(&nelovo, NUM_INSTRS, &num_instr, &invalid_instr_addr,
                     0) == ERROR);

  load_program(&nelovo, program2, NUM_INSTRS);
  assert(run_program(&nelovo, NUM_INSTRS, &num_instr, &invalid_instr_addr,
                     0) == HALTED);

  printf("All assertions succeeded convincingly!\n");

  return 0;
}
