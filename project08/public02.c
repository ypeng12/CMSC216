#include <stdio.h>
#include "fakefile.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 2 (public02.c)
 *
 * Tests the basic operation of read_fakefile() and print_fakefile() with a
 * fakefile that has a few rules.
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

  fakefile= read_fakefile("public02.fakefile");

  print_fakefile(fakefile);

  return 0;
}
