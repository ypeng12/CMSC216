#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* CMSC 216, Sprint 2022, Project #10
 * Public test 7 (public7.c)
 *
 * Runs the grep-threaded.x program with several filenames on the command
 * line, so several threads will be created.  Some of the files have
 * occurrences of the word to be searched for.  This test uses valgrind to
 * check for memory leaks and corruption of the heap.
 *
 * This test runs your program as (all the arguments are actually on one
 * line but the line would be longer than 80 characters so we just used a
 * backslash and wrote it on more than one line)
 *
 *   ./grep-threaded.x sheep public7a.inputdata public7b.inputdata \
 *                           public7c.inputdata public7d.inputdata \
 *                           public7e.inputdata public7f.inputdata
 *
 * HOWEVER, the test actually runs the command above under valgrind, with
 * some arguments to valgrind.  (But if you want to debug your program for
 * this test you are not going to run gdb on valgrind, you are going to run
 * it on your program grep-threaded.x with the arguments above.)
 *
 * (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define FILENAMES "public7a.inputdata public7b.inputdata public7c.inputdata " \
                  "public7d.inputdata public7e.inputdata public7f.inputdata"
#define COMMAND_TO_RUN "valgrind -q --leak-check=full --error-exitcode=100 " \
                       "./grep-threaded.x sheep " FILENAMES

int main(void) {
  assert(system(COMMAND_TO_RUN) == 0);

  printf("Your program didn't have any memory problems!\n");

  return 0;
}
