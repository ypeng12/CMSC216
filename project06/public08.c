#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 8 (public08.c)
 *
 * Tests some special cases for the touch() and mkdir() functions.
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

  /* these are some special characters that are valid in file and directory
     names */
  mkdir(&filesystem, "$quirrel");
  mkdir(&filesystem, "chip-munk");
  touch(&filesystem, "p*rc&pine");
  ls(&filesystem, ".");
  printf("\n");

  /* but '/' cannot appear anywhere in a file or directory name (error
     case) */
  mkdir(&filesystem, "chip/munk");
  mkdir(&filesystem, "/squirrel");
  mkdir(&filesystem, "porcupine/");
  ls(&filesystem, ".");
  printf("\n");

  /* these are also either error cases or just have no effect */
  touch(&filesystem, ".");
  mkdir(&filesystem, "/");
  touch(&filesystem, "..");
  ls(&filesystem, ".");

  return 0;
}
