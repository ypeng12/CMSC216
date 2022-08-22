#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 1 (public01.c)
 *
 * Tests the basic operation of the touch() function to create a filesystem
 * with several files, and lists them using the ls() function.
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

  
 
  touch(&filesystem, "koala");
  touch(&filesystem, "sheep");
  touch(&filesystem, "platypus");
  touch(&filesystem, "numbat");
  touch(&filesystem, "quokka");

  ls(&filesystem, ".");

  return 0;
}
