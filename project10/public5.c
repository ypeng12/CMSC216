#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Spring 2022, Project #10
 * Public test 5 (public5.c)
 *
 * Runs the grep-threaded.x program with two filenames on the command line,
 * so two threads will be created.  Neither of the files has an occurrence
 * of the word to be searched for.
 *
 * This test runs your program as
 *
 *   ./grep-threaded.x sheep public5a.inputdata public5b.inputdata
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define FILENAMES "public5a.inputdata public5b.inputdata"
#define COMMAND_TO_RUN "./grep-threaded.x sheep " FILENAMES

int main(void) {
  assert(system(COMMAND_TO_RUN) == 0);

  return 0;
}
