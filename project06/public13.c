#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 13 (public13.c)
 *
 * Tests calling rm() to remove some directories from a filesystem.  This
 * test just checks for correct operation of rm(), it does not check that
 * there are no memory leaks or errors in the heap.
 *
 * In order to run valgrind on this test note that it will unavoidably have
 * memory leaks, since it does not call rmfs() as the last operation.  So
 * when running valgrind on this test, add the valgrind option
 * --leak-check=no to turn off checking for memory leaks.  Then fix any
 * *other* errors that valgrind identifies (other than memory leaks).
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main() {
  Ournix filesystem;

  mkfs(&filesystem);

  mkdir(&filesystem, "koala");
  mkdir(&filesystem, "sheep");
  mkdir(&filesystem, "platypus");
  mkdir(&filesystem, "numbat");
  mkdir(&filesystem, "quokka");

  ls(&filesystem, ".");
  printf("\n");

  rm(&filesystem, "quokka");
  rm(&filesystem, "numbat");

  ls(&filesystem, ".");

  return 0;
}
