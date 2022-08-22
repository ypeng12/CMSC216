#include <stdio.h>
#include <string.h>
#include "ournix.h"

/* CMSC 216, Spring 2022, Project #6
 * Public test 3 (public03.c)
 *
 * Tests using mkdir() and touch() to create a filesystem with mixed files
 * and subdirectories, and lists them using ls().  Also tests that your
 * mkdir() and touch() functions are making copies of their argument
 * strings, and not just doing pointer aliasing.
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
  char name[20];

  mkfs(&filesystem);

  /* if touch() or mkdir() are just doing pointer aliasing, instead of
     creating new memory for each file or directory name, all the files and
     directories will end up having the same value */
  strcpy(name, "goat");
  touch(&filesystem, name);
  strcpy(name, "sheep");
  mkdir(&filesystem, name);
  strcpy(name, "platypus");
  mkdir(&filesystem, name);
  strcpy(name, "hawk");
  touch(&filesystem, name);
  strcpy(name, "hippopotamus");
  touch(&filesystem, name);
  strcpy(name, "numbat");
  mkdir(&filesystem, name);
  strcpy(name, "quokka");
  mkdir(&filesystem, name);
  strcpy(name, "ostrich");
  touch(&filesystem, name);
  strcpy(name, "salamander");
  touch(&filesystem, name);
  strcpy(name, "koala");
  mkdir(&filesystem, name);

  ls(&filesystem, ".");

  return 0;
}
