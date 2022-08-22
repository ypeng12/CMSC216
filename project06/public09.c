#include <stdio.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 9 (public09.c)
 *
 * Tests calling some of the functions with NULL pointer arguments.
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

  touch(&filesystem, "dolphin");
  mkdir(&filesystem, "sheep");
  mkdir(&filesystem, "platypus");
  mkdir(&filesystem, "hawk");
  touch(&filesystem, "hippopotamus");

  /* here are the calls with NULL pointer parameters- will your functions
     survive the challenge? */
  touch(NULL, "test1");
  mkdir(NULL, "test2");
  cd(NULL, "test3");
  ls(NULL, "test4");

  /* ensure that your filesystem data structure is still valid after the
     obnoxious calls above by adding some new components and listing
     things */
  touch(&filesystem, "numbat");
  touch(&filesystem, "quokka");
  touch(&filesystem, "goat");
  mkdir(&filesystem, "elephant");
  mkdir(&filesystem, "koala");

  ls(&filesystem, ".");

  return 0;
}
