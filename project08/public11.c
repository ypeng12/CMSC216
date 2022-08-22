#include <stdio.h>
#include <stdlib.h>
#include "fakefile.h"
#include "memory-checking.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 11 (public11.c)
 *
 * Tests calling clear_fakefile(), then checks that there are no memory
 * leaks or errors in the heap.
 *
 * In order to run valgrind on this test, note the following:
 *
 * 1. This test should have NO memory leaks, so do NOT use the valgrind option
 *    --leak-check=no.  (If valgrind reports any memory leaks you need to fix
 *    your code to eliminate them.)
 *
 * 2. As Project #6 explained, valgrind does not work with our memory
 *    checking functions, so to use valgrind with this test, recompile it
 *    using -DENABLE_VALGRIND- see the project assignment for details.
 *    (Using -DENABLE_VALGRIND means you do *not* need to copy this test to
 *    another file and remove anything from it to use valgrind.)  Then after
 *    fixing your memory problems, recompile WITHOUT that option, as the
 *    project assignment explains.
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Fakefile *fakefile;

  #if !defined(ENABLE_VALGRIND)
  setup_memory_checking();
  #endif

  fakefile= read_fakefile("public11.fakefile");
  print_fakefile(fakefile);
  clear_fakefile(&fakefile);

  free(fakefile);

  #if !defined(ENABLE_VALGRIND)
  check_heap();
  #endif

  /* if this is the only thing printed after the normal output produced by
   * the calls above then the heap must be valid and there must not have
   * been any memory leaks
   */
  printf("\nEverything in the heap looks valid!\n");

  return 0;
}
