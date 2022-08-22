#include <stdio.h>
#include <assert.h>
#include "fakefile.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 3 (public03.c)
 *
 * Tests the basic operation of lookup_target().
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
  const char *targets[]= {"main.x", "functions.o", "main.o", "clean"};
  int i;

  fakefile= read_fakefile("public03.fakefile");

  for (i= 0; i < ARRSIZE(targets); i++)
    assert(lookup_target(fakefile, targets[i]) == i);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
