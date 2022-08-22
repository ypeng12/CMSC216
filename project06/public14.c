#include <stdio.h>
#include "ournix.h"
#include "memory-checking.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 14 (public14.c)
 *
 * Tests calling rmfs() on a filesystem that contains some files (in the
 * root directory), then checks that there are no memory leaks or errors in
 * the heap.
 *
 * Note that Makefile rules for this test will be different than for most
 * other ones.
 *
 * In order to run valgrind on this test, note the following:
 *
 * 1. This test should have NO memory leaks, so do NOT use the valgrind option
 *    --leak-check=no.  (If valgrind reports any memory leaks you need to fix
 *    your code to eliminate them.)
 *
 * 2. As the project assignment explains, valgrind does not work with our
 *    memory checking functions, so to use valgrind with this test, copy the
 *    test to another file (for example cp public14.c public14-mine.c), edit
 *    the copy to REMOVE the calls to setup_memory_checking() and
 *    check_heap(), and compile the copy (adding the -g compilation option,
 *    necessary to use valgrind) and run this compiled program under valgrind.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Ournix filesystem;

  setup_memory_checking();

  mkfs(&filesystem);

  touch(&filesystem, "koala");
  touch(&filesystem, "sheep");
  touch(&filesystem, "platypus");
  touch(&filesystem, "numbat");
  touch(&filesystem, "quokka");

  ls(&filesystem, ".");

  rmfs(&filesystem);  /* now trash the whole thing */

  check_heap();

  /* if this is the only thing printed after the normal output produced by
   * the calls above then the heap must be valid and there must not have
   * been any memory leaks
   */
  printf("\nEverything in the heap looks valid!\n");

  return 0;
}
