#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Spring 2022, Project #10
 * Public test 4 (public4.c)
 *
 * Runs the grep-threaded.x program with two filenames on the command line,
 * so two threads will be created.  Both of the files have an occurrence of
 * the word to be searched for.
 *
 * This test runs your program as (with two filenames to read from)
 *
 *   ./grep-threaded.x sheep public4a.inputdata public4b.inputdata
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define FILENAMES "public4a.inputdata public4b.inputdata"
#define COMMAND_TO_RUN "./grep-threaded.x sheep " FILENAMES

int main(void) {
  assert(system(COMMAND_TO_RUN) == 0);

  return 0;
}
