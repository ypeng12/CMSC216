#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 7 (public07.c)
 *
 * Tests the touch() command file timestamps.
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

  touch(&filesystem, "llama");
  touch(&filesystem, "poodle");
  touch(&filesystem, "sheep");

  /* the files all exist so these just update their timestamps */
  touch(&filesystem, "sheep");
  touch(&filesystem, "sheep");
  touch(&filesystem, "poodle");
  touch(&filesystem, "poodle");
  touch(&filesystem, "sheep");
  touch(&filesystem, "sheep");
  touch(&filesystem, "poodle");
  touch(&filesystem, "sheep");

  ls(&filesystem, "llama");
  ls(&filesystem, "poodle");
  ls(&filesystem, "sheep");

  return 0;
}
