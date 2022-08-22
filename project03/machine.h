/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
 * SERVER. */

#define NUM_BYTES 16384
#define BYTES_PER_WORD 4
#define NUM_WORDS (NUM_BYTES / BYTES_PER_WORD)
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define R12 12
#define R13 13

typedef unsigned int Mach_word;

typedef enum { HALT, ADD, SUB, MUL, DIV, REM, NEG, AND, OR, NOT, EQL,
               NEQ, LT, GT, LE, GE, TEST, MOVE, LI, LW, SW, READ,
               PRT } Operation;

unsigned short print_instruction(Mach_word instr);
unsigned short disassemble(const Mach_word program[],
                           unsigned short max_addr);
unsigned short is_valid(Mach_word word);
short check_branches(const Mach_word program[], unsigned short max_addr);
