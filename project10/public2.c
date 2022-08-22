#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Spring 2022, Project #10
 * Public test 2 (public2.c)
 *
 * Runs the grep-threaded.x program with just one filename on the command
 * line, meaning only one thread will be created (besides the main thread).
 * The file does not have an occurrence of the word to be searched for.
 *
 * This test runs your program as
 *
 *   ./grep-threaded.x sheep public2.inputdata
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define FILENAME " "
#define COMMAND_TO_RUN "./grep-threaded.x sheep " FILENAME

int main(void) {
  assert(system(COMMAND_TO_RUN) == 0);

  return 0;
}
