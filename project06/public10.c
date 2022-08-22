#include <stdio.h>
#include "ournix.h"
#include "driver.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 10 (public10.c)
 *
 * Tests creating a larger filesystem with various files and directories,
 * and calls many of the functions on it.
 *
 * Link this example with the driver object file driver.o, and run the
 * executable with input redirected from public10.input.  (Hint #1: you used
 * input redirection to run every test in Project #2.)  (Hint #2: Makefile
 * rules for this test will be different than for the other ones.)
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

  driver(&filesystem);

  rmfs(&filesystem);
  return 0;
}
