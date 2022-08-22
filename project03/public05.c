#include <stdio.h>
#include "machine.h"

/* CMSC 216, Spring 2022, Project #3
 * Public test 5 (public05.c)
 *
 * Tests calling disassemble() on a program with some valid instructions.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define MAX_ADDR 16

int main(void) {
  Mach_word program[]= {0x0858c000, 0x109d4000, 0x1ce1c000, 0x21264000,
                        0x316ac000};

  disassemble(program, MAX_ADDR);

  return 0;
}
