#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <assert.h>
#define LINE_SZ 256

typedef struct {
 	char *search;
	char *file;
} Point;


static void *bruh(void *arg);

static void *bruh(void *arg) {
	int *result = malloc(sizeof(*result));
	
	Point point= * (Point *) arg;
	char line[LINE_SZ], *string_to_search_for, *file;
	long total = 0;
	FILE *fp;  

	file = point.file;
	string_to_search_for = point.search;

 	*result = 0;
    
    fp= fopen(file, "r");  /* open file for reading */
	
	/* silently ignore nonexistent files, or ones that there was an error
		trying to open */
	if (fp != NULL) {
		
		total= 0;

		/* see the explanation in the project assignment regarding what this
			is for */
		/* randomdelay(argv[i]); */

		while (fgets(line, LINE_SZ, fp) != NULL)
			if (strstr(line, string_to_search_for) != NULL){
				
				total++;
		}
	} else{
		return result;
	}


      fclose(fp);

	*result = total;
	return result;  
}

int main(int argc, char *argv[]) {
	pthread_t *tids;
	long file_total = 0;
	int i;
	void *ret_ptr = NULL;
	Point *pt_ptr;

  if (argc > 2) { /* only use threads if there are files 
             on cmd line */

    /* create dynamically allocated list of tids */
    tids = malloc((argc-2)*sizeof(*tids));


	pt_ptr= malloc((argc-2)*sizeof(Point));
	

    /* check for malloc failure */
    if (tids != NULL) {
		
      /* create a thread for each file name */
      for (i = 0; i < argc-2; i++) { 
		
		assert(pt_ptr != NULL);

		pt_ptr[i].search = argv[1];
		pt_ptr[i].file = argv[i+2];

		pthread_create(&tids[i], NULL, bruh, &pt_ptr[i]);

      }


    /* reap each thread and get its return value */
      for (i = 0; i < argc-2; i++) {
        pthread_join(tids[i], &ret_ptr);
        file_total += * (int *) ret_ptr;
        free(ret_ptr);
        ret_ptr = NULL;
      }

    }

	free(tids);
	tids = NULL;
	free(pt_ptr);
	pt_ptr = NULL;
    
  }


  printf("%ld\n", file_total);
  return 0;
}
