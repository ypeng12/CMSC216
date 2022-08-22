#include <stdio.h>
#include <unistd.h>  /* for sleep() */
#include "fakefile.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 5 (public05.c)
 *
 * Tests the basic operation of do_action().  (The test waits for a second
 * between performing actions.)
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

  fakefile= read_fakefile("public05.fakefile");

  do_action(fakefile, 0);
  printf("\n");
  sleep(1);

  do_action(fakefile, 1);
  printf("\n");
  sleep(1);

  do_action(fakefile, 2);
  printf("\n");
  sleep(1);

  do_action(fakefile, 3);

  return 0;
}
