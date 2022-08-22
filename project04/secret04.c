#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 4 (secret04.c)
 *
 * Tests calling run_program() with a Nelovo program in which the
 * program should execute exactly max_instrs instructions (the
 * edge case for the value of max_instrs).
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
  Mach_word value;
  unsigned short num_instr= 0, invalid_instr_addr= 0;

  load_program(&nelovo, program, NUM_INSTRS);

  assert(run_program(&nelovo, NUM_INSTRS, &num_instr, &invalid_instr_addr,
                     0) == HALTED);

  /* check the results */
  get_register(nelovo, R0, &value);
  assert(value == 3);
  get_register(nelovo, R1, &value);
  assert(value == 7);
  get_register(nelovo, R2, &value);
  assert(value == 8);
  get_register(nelovo, R3, &value);
  assert(value == 10);
  get_register(nelovo, R4, &value);
  assert(value == 4);
  get_register(nelovo, R5, &value);
  assert(value == 40);
  get_register(nelovo, R6, &value);
  assert(value == 5);
  get_register(nelovo, R7, &value);
  assert(value == 5);

  printf("All assertions succeeded convincingly!\n");

  return 0;
}
