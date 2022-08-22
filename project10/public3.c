#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Spring 2022, Project #10
 * Public test 3 (public3.c)
 *
 * Runs the grep-threaded.x program with two filenames on the command line,
 * so two threads will be created.  One of the files has occurrences of the
 * word to be searched for.
 *
 * This test runs your program as (the word to search for is "are")
 *
 *   ./grep-threaded.x are public3a.inputdata public3b.inputdata
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define FILENAMES "public3a.inputdata public3b.inputdata"
#define COMMAND_TO_RUN "./grep-threaded.x are " FILENAMES

int main(void) {
  assert(system(COMMAND_TO_RUN) == 0);

  return 0;
}
