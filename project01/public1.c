#include <stdio.h>
#include <assert.h>
#include "functions.h"

/* CMSC 216, Spring 2022, Project #1
 * Public test 1 (public1.c)
 *
 * Tests calling classify_triangle(216, 216, 216).
 *
 * Note that this test also calls the other two functions but does not check
 * their results for correctness- it calls them only so you will be able to
 * tell that your other functions compile successfully on the submit server.
 * When you are writing your own tests, note that only the first assertion
 * below is actually doing anything (it is an example of how you should be
 * testing your functions yourself, as opposed to what follows it in this
 * test).
 *
 * (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(void) {
  long result;

  assert(classify_triangle(131, 132, 216) == 0);

  result= reverse_digits(216) + catalan(12);
  /* this assertion will always be true, regardless of what your
     reverse_digits() and catalan() functions return */
  assert(result == 1 || result != 1);

  printf("\nThe test passed!!!!\n");

  return 0;
}
