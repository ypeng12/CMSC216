#include <stdio.h>
#include <string.h>

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

#define LINE_SZ 256

int main(int argc, char *argv[]) {
  FILE *fp;
  char line[LINE_SZ], *string_to_search_for;
  int i, total= 0;

  if (argc > 2) {
    string_to_search_for= argv[1];
    for (i= 2; i < argc; i++) {
      fp= fopen(argv[i], "r");

      /* silently ignore nonexistent files, or ones that there was an error
         trying to open */
      if (fp != NULL) {
        while (fgets(line, LINE_SZ, fp) != NULL)
          if (strstr(line, string_to_search_for) != NULL)
            total++;

        fclose(fp);
      }
    }
  }

  printf("%d\n", total);

  return 0;
}
