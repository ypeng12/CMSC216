#include <stdio.h>
#include <assert.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 2 (secret02.c)
 *
 * Tests calling check_branches() on a program with an invalid branch
 * instruction that has an too--large address.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRS 9
#define MAX_ADDR ((NUM_INSTRS - 1) * BYTES_PER_WORD)

int main(void) {
  Nelovo nelovo;
  Mach_word program[NUM_WORDS]= {0x48800064,   /*  0: li   R2 100   */
                                 0x48c00064,   /*  4: li   R3 100   */
                                 0x050c8000,   /*  8: add  R4 R3 R2 */
                                 0x150c8000,   /*  c: rem  R4 R3 R2 */
                                 0x3114c000,   /* 10: lt   R4 R5 R3 */
                                 0x40800004,   /* 14: test R2  4    */
                                 0x40c00028,   /* 18: test R3 40 (invalid) */
                                 0x4100000c,   /* 1c: test R4 12    */
                                 0x00000000};  /* 20: halt          */
  unsigned short invalid_instr_addr= 0;

  load_program(&nelovo, program, NUM_INSTRS);

  assert(check_branches(&nelovo, MAX_ADDR, &invalid_instr_addr) == 0);
  /* the instruction at address 8 is invalid */
  assert(invalid_instr_addr == 24);

  printf("All assertions succeeded convincingly!\n");

  return 0;
}
