#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "fakefile.h"

/* CMSC 216, Spring 2022, Project #8
 * Public test 4 (public04.c)
 *
 * Tests the basic operation of num_dependencies() and get_dependency().
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
  const char *targets[]= {"main.x", "functions.o", "main.o", "checklength.x",
                          "clean"};
  int expected_num_dependencies[]= {4, 2, 2, 1, 0};
  const char *expected_dependency_names[]= {
    "main.o", "functions.o", "memory-checking.o", "safe-fork.o",
    "functions.c", "functions.h", "main.c", "functions.h", "checklength.c"
  };
  int i, j, pos= 0;

  fakefile= read_fakefile("public04.fakefile");

  for (i= 0; i < ARRSIZE(targets); i++) {
    assert(num_dependencies(fakefile, i) == expected_num_dependencies[i]);
    for (j= 0; j < expected_num_dependencies[i]; j++)
      assert(strcmp(get_dependency(fakefile, i, j),
                    expected_dependency_names[pos++]) == 0);
  }

  printf("Yet again, all assertions were successful!\n");

  return 0;
}
