#include <stdio.h>
#include <assert.h>
#include "functions.h"

int main(void) {
  long result;

  assert(classify_triangle(131, 132, 216) == 0);

  assert(classify_triangle(3, 4, 5) == 0);
  assert(classify_triangle(3, 3, 5) == 2);
  assert(classify_triangle(3, 3, 3) == 3);

  assert(classify_triangle(-1, 3, 5) == -1);
  assert(classify_triangle(3, -3, 5) == -1);
  assert(classify_triangle(3, 3, -5) == -1);
  assert(classify_triangle(3, 3, 6) == -1);

  printf("\nPassed Triangle!\n");

  result= reverse_digits(216) + catalan(12);
  /* this assertion will always be true, regardless of what your                                                           
     reverse_digits() and catalan() functions return */
  assert(result == 1 || result != 1);
  /*  printf("%lu\n",reverse_digits(216)); */ 
  assert(reverse_digits(216) == 612);
  assert(reverse_digits(110) == -1);
  assert(reverse_digits(0) == 0);
  assert(reverse_digits(2345) == 5432);

  printf("\nPassed reverse_digits!\n");

  assert(catalan(-1) == -1);
  assert(catalan(0) == 1);
  assert(catalan(1) == 1);
  /*  
printf("%lu\n",catalan(5));
  printf("%lu\n",catalan(6));
  printf("%lu\n",catalan(7));
  printf("%lu\n",catalan(34));
  printf("%lu\n",catalan(9));
*/
  assert(catalan(2) == 2);
  assert(catalan(3) == 5);
  assert(catalan(4) == 14);
  assert(catalan(5) == 42);

  printf("\nPassed catalan!\n");

  printf("\nThe test all passed!\n");

  return 0;
}
