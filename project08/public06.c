#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fakefile.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 6 (public06.c)
 *
 * Tests calling do_action() when the command to be executed doesn't exit
 * normally.  (If you are not passing this test check carefully how you are
 * getting the exit status of the child process created in do_action(),
 * because there may be a problem there.)
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
  Fakefile *fakefile;

  fakefile= read_fakefile("public06.fakefile");

  /* compile a program that we know isn't going to exit normally */
  system("gcc public06-testprogram.c -o public06-testprogram.x");

  /* performing this action will run the program that was just compiled
     above, which as you can see by looking at public06-testprogram.c, has
     an error so it will have a nonzero exit status */
  assert(do_action(fakefile, 0) == -1);

  printf("Yet again, all assertions were successful!\n");

  /* remove the compiled program, just so it doesn't throw off anything if
     the test is run again later (remove() is in stdio.h, and in Reek
     Chapter 15) */
  assert(remove("public06-testprogram.x") != -1);

  return 0;
}
