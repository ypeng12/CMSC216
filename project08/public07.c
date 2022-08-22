#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* for sleep() */
#include <assert.h>
#include "fakefile.h"
#include "make-target.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 7 (public07.c)
 *
 * Tests calling make_target() on the target of a single-rule fakefile, when
 * the target already exists and is already newer than its dependency (the
 * action should not be performed).
 *
 * In order to run valgrind on this test note that it will unavoidably have
 * memory leaks, since it does not call clear_fakefile() as the last
 * operation.  So when running valgrind on this test, add the valgrind
 * option --leak-check=no to turn off checking for memory leaks.  Then fix
 * any *other* errors that valgrind identifies (other than memory leaks).
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  Fakefile *fakefile;

  fakefile= read_fakefile("public07.fakefile");

  /* see Section 4.2 of the project assignment */
  setvbuf(stdout, NULL, _IONBF, 0);

  /* remove files if they already exist (from a previous execution); -f
     suppresses error messages even if some or all of the files don't exist */
  system("rm -f older-file file newer-file");
  system("date > older-file");
  /* sleep for 1 second before creating files, to ensure that their
     timestamps are later */
  sleep(1);
  system("date > file");
  sleep(1);
  system("date > newer-file");

  assert(make_target(fakefile, "file") == 0);

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
