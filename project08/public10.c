#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* for sleep() */
#include <assert.h>
#include "fakefile.h"
#include "make-target.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 10 (public10.c)
 *
 * Tests calling make_target() using a fakefile similar to the one in the
 * project assignment, to build a program main.x, which is then executed.
 * When run, main.x just prints 216.
 *
 * In order to run valgrind on this test note that it will unavoidably have
 * memory leaks, since it does not call clear_fakefile() as the last
 * operation.  So when running valgrind on this test, add the valgrind
 * option --leak-check=no to turn off checking for memory leaks.  Then fix
 * any *other* errors that valgrind identifies (other than memory leaks).
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Fakefile *fakefile= read_fakefile("public10.fakefile");

  fakefile= read_fakefile("public10.fakefile");

  /* see Section 4.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* remove files if they already exist (from a previous execution); -f
     suppresses error messages even if some or all of the files don't exist */
  system("rm -f main.x main.o functions.o");

  assert(make_target(fakefile, "main.x") == 0);

  printf("Running main.x now, it prints ");
  system("./main.x");

  printf("\nYet again, all assertions were successful!\n");

  return 0;
}
