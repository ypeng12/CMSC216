#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Spring 2022, Project #10
 * Public test 6 (public6.c)
 *
 * Runs the grep-threaded.x program with three threads on the command line,
 * so two threads will be created.  None of the files has an occurrence of
 * the word to be searched for.  One file is a zero-length file with no
 * contents.
 *
 * This test runs your program as (all the arguments are actually on one
 * line but the line would be longer than 80 characters so we just used a
 * backslash and wrote it on more than one line)
 *
 *   ./grep-threaded.x sheep public6a.inputdata nonexistent-file \
 *                           public6b.inputdata"
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define FILENAMES "public6a.inputdata nonexistent-file public6b.inputdata"
#define COMMAND_TO_RUN "./grep-threaded.x sheep " FILENAMES

int main(void) {
  assert(system(COMMAND_TO_RUN) == 0);

  return 0;
}
