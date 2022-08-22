#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #4
 * Secret test 1 (secret01.c)
 *
 * Tests calling disassemble() on a program with instructions that use but
 * don't modify their first register operand and that have R13 (the program
 * counter) as the first register operand, which is valid.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define NUM_INSTRS 3

int main(void) {
  Nelovo nelovo;
  Mach_word program[NUM_WORDS]= {0x43400008,   /* test R13 8 */
                                 0x5340000c,   /* sw   R13 12 */
                                 0x5b400000};  /* prt  R13 */

  load_program(&nelovo, program, NUM_INSTRS);

  disassemble(nelovo, (NUM_INSTRS - 1) * 4);

  return 0;
}
