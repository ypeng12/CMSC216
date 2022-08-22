#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 7 (secret07.c)
 *
 * Tests calling run_program() with a Nelovo program that has an invalid
 * instruction because it tries to modify the program counter register R13.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRS 6

int main(void) {
  Nelovo nelovo;
  /* program1 has an instruction that incorrectly tries to modify the
     program counter register, while program2 is valid */
  Mach_word program1[NUM_WORDS]= {0x4a0004bc, 0x4a400849, 0x4a800913,
                                  0x4ac00ca0, 0x176ac000, 0x00000000};
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
