#include <stdio.h>
#include <assert.h>
#include "machine.h"
#define MAX_ADDR 16

int main(void) {
  Mach_word program[]= {
                        0x48800064,   /*  0: li    R2 100   */
                        0x48c00064,   /*  4: add   R4 R3 R2 */
                        0x00000000,  /*  8  : halt           */
                        0x3114c000,   /* c: lt     R4 R5 R3 */
                        0x40c00007,   /*  10: test  R3 7     */
                        };
  /* the instruction at address 0 is invalid */
  assert(check_branches(program, MAX_ADDR) == 0x10);

  printf("The assertion worked like a charm!\n");

  return 0;
}
