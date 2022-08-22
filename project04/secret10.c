#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 10 (secret10.c)
 *
 * Tests the value of the program counter is right after run_program()
 * returns in different cases.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRS 9

int main(void) {
  Nelovo nelovo;
  Mach_word program[NUM_WORDS]= {0x48000003,   /* li  R0 3 */
                                 0x48400007,   /* li  R1 7 */
                                 0x48800008,   /* li  R2 8 */
                                 0x04c04000,   /* add R3 R0 R1 */
                                 0x09040000,   /* sub R4 R1 R0 */
                                 0x0d4d0000,   /* mul R5 R3 R4 */
                                 0x11948000,   /* div R6 R5 R2 */
                                 0x15d44000,   /* rem R7 R5 R1 */
                                 0x00000000};  /* halt */
  Mach_word result= 0;
  unsigned short num_instr= 0, invalid_instr_addr= 0;

  /* run for only three instructions */
  load_program(&nelovo, program, NUM_INSTRS);
  run_program(&nelovo, 3, &num_instr, &invalid_instr_addr, 0);
  get_register(nelovo, R13, &result);
  assert(result == 12);

  /* run for five instructions */
  load_program(&nelovo, program, NUM_INSTRS);
  run_program(&nelovo, 5, &num_instr, &invalid_instr_addr, 0);
  get_register(nelovo, R13, &result);
  assert(result == 20);

  /* run until the program halts */
  load_program(&nelovo, program, NUM_INSTRS);
  run_program(&nelovo, 100, &num_instr, &invalid_instr_addr, 0);
  get_register(nelovo, R13, &result);
  assert(result == 32);

  printf("All assertions succeeded convincingly!\n");

  return 0;
}
