#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 9 (secret09.c)
 *
 * Tests calling run_program() with Nelovo programs that have invalid lw,
 * sw, and test instructions with incorrect memory addresses.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRS 6

int main(void) {
  Nelovo nelovo;
  /* program1 has a sw instruction with an invalid address, program2 has an
     lw instruction with an invalid address, program3 has a test instruction
     with an invalid address, and program4 is valid */
  Mach_word program1[NUM_WORDS]= {0x48c0000b, 0x49000016, 0x49400021,
                                  0x50c00309, 0x4980002c, 0x00000000};
  Mach_word program2[NUM_WORDS]= {0x48c0000b, 0x49000016, 0x49400021,
                                  0x4d800000, 0x4d8003e7, 0x00000000};
  Mach_word program3[NUM_WORDS]= {0x48c0000b, 0x49000016, 0x49400021,
                                  0x4d800000, 0x4180014d, 0x00000000};
  Mach_word program4[NUM_WORDS]= {0x48c0000b, 0x49000016, 0x49400021,
                                  0x058d0000, 0x0dd14000, 0x00000000};
  unsigned short num_instr= 0, invalid_instr_addr= 0;

  load_program(&nelovo, program1, NUM_INSTRS);
  assert(run_program(&nelovo, NUM_INSTRS, &num_instr, &invalid_instr_addr,
                     0) == ERROR);

  load_program(&nelovo, program2, NUM_INSTRS);
  assert(run_program(&nelovo, NUM_INSTRS, &num_instr, &invalid_instr_addr,
                     0) == ERROR);

  load_program(&nelovo, program3, NUM_INSTRS);
  assert(run_program(&nelovo, NUM_INSTRS, &num_instr, &invalid_instr_addr,
                     0) == ERROR);

  load_program(&nelovo, program4, NUM_INSTRS);
  assert(run_program(&nelovo, NUM_INSTRS, &num_instr, &invalid_instr_addr,
                     0) == HALTED);

  printf("All assertions succeeded convincingly!\n");

  return 0;
}
