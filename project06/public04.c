#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 4 (public04.c)
 *
 * Tests using the cd() function to change to a subdirectory, creates some
 * files in it, and lists them.
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

  mkdir(&filesystem, "sheep");
  mkdir(&filesystem, "koala");
  cd(&filesystem, "koala");
  
  mkdir(&filesystem, "sheep");
  mkdir(&filesystem, "platypus");
  mkdir(&filesystem, "numbat");
  mkdir(&filesystem, "quokka");

  /* this will not list koala, because we are inside koala */
  
  ls(&filesystem, ".");


  return 0;
}
