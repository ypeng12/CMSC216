#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 11 (public11.c)
 *
 * Tests calling rmfs() on a filesystem that contains some files (in the
 * root directory).  This test just checks for correct operation of rmfs(),
 * it does not check that there are no memory leaks or errors in the heap.
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

  touch(&filesystem, "koala");
  touch(&filesystem, "sheep");
  touch(&filesystem, "platypus");
  touch(&filesystem, "numbat");
  touch(&filesystem, "quokka");

  ls(&filesystem, ".");
  printf("\n");

  rmfs(&filesystem);  /* now trash the whole thing */

  /* now reinitialize it and add some new files and ensure that things are
     valid */
  mkfs(&filesystem);

  touch(&filesystem, "giraffe");
  touch(&filesystem, "penguin");
  touch(&filesystem, "parrot");

  ls(&filesystem, ".");

  return 0;
}
