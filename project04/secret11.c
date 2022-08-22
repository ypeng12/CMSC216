#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 11 (secret11.c)
 *
 * Tests calling run_program() to run a small but semi-realistic Nelovo
 * program that reads two numbers and calculates and prints the first number
 * raised to the power of the second one.  Run this test with input
 * redirected from secret11.input.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Nelovo machine;
  Mach_word pgm[]= {0x54000000,   /*  0: read  R0 */
                    0x54400000,   /*  4: read  R1 */
                    0x48800001,   /*  8: li    R2 1 */
                    0x48c00001,   /* 12: li    R3 1 */
                    0x49000001,   /* 16: li    R4 1 */
                    0x49400001,   /* 20: li    R5 1 */
                    0x34c84000,   /* 24: gt    R3 R2 R1 */
                    0x40c0002c,   /* 28: test  R3 44 */
                    0x0d540000,   /* 32: mul   R5 R5 R0 */
                    0x04890000,   /* 36: add   R2 R2 R4 */
                    0x40800018,   /* 40: test  R2 20 */
                    0x59400000,   /* 44: prt   R5 */
                    0x00000000};  /* 48: halt */
  unsigned short num_instr= 0, invalid_instr_addr= 0;

  load_program(&machine, pgm, 13);

  /* run to compute 0^0, 5^0, 1^6, 6^1, 2^10, 10^4, and 6^4 */
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  printf("\n");

  return 0;
}
