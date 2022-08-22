#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 6 (public06.c)
 *
 * Tests some special cases for the ls() function, including calling it on
 * an empty filesystem.
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

int main(void) {
  Ournix filesystem;

  mkfs(&filesystem);

  /* should not print anything because the filesystem is currently empty */
  ls(&filesystem, ".");
  

  touch(&filesystem, "goat");
  mkdir(&filesystem, "sheep");
  mkdir(&filesystem, "platypus");
  touch(&filesystem, "hawk");
  touch(&filesystem, "hippopotamus");

  cd(&filesystem, "sheep");
  mkdir(&filesystem, "koala");
  touch(&filesystem, "salamander");
  mkdir(&filesystem, "numbat");
  mkdir(&filesystem, "quokka");
  touch(&filesystem, "ostrich");

  ls(&filesystem, ".");
  printf("\n");

  ls(&filesystem, "..");
  printf("\n");

  ls(&filesystem, "/");

  return 0;
}
