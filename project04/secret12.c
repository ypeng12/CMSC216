#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 12 (secret12.c)
 *
 * Tests calling run_program() to run a small but semi-realistic Nelovo
 * program that reads a number and calculates and prints its factorial.  Run
 * this test with input redirected from secret12.input.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Nelovo machine;
  Mach_word pgm[]= {0x54400000,   /*  0: read  R1 */
                    0x48800001,   /*  4: li    R2 1 */
                    0x48c00001,   /*  8: li    R3 1 */
                    0x49000001,   /* 12: li    R4 1 */
                    0x35484000,   /* 16: gt    R5 R2 R1 */
                    0x41400024,   /* 20: test  R5 36 */
                    0x0ccc8000,   /* 24: mul   R3 R3 R2 */
                    0x04890000,   /* 28: add   R2 R2 R4 */
                    0x41000010,   /* 32: test  R4 16 */
                    0x58c00000,   /* 36: prt   R3 */
                    0x00000000};  /* 40: halt */
  unsigned short num_instr= 0, invalid_instr_addr= 0;

  load_program(&machine, pgm, 11);

  /* run with inputs 0, 1, 5, and 10, to compute 0!, 1!, 5!, and 10! */
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  run_program(&machine, 1000, &num_instr, &invalid_instr_addr, 0);
  printf("\n");

  return 0;
}
