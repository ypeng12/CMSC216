/*
Yuliang Peng CMSC216 Sections: 0205
Project 07
I pledge on my honor that I have not given or received any
unauthorized assistance on this project.

gcc papersize.c safe-fork.o -o papersize.x
papersize.x <document1| diff -b - public1.results
papersize.x <document2| diff -b - public2.results

papersize.x < public3
papersize.x<public4
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "safe-fork.h"
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>  /* needed on the submit server to use pid_t */

/* 
max len of input & output lines is 999
*/ 
#define MAX_INPUT 999  

extern char **environ;
/*
This checklength.c needs to read the line, store each 
line and then print out, the max for storing data is 999
and when printing, the line is over the 80 then print "X",
more detail will explain later.
*/


int main(void) {

  char line[MAX_INPUT];
  unsigned int num_chars = 0;
  unsigned int result  = 0;


  pid_t pid;
  int pipefd[2];

  assert(pipe(pipefd) != -1);
  pid= safe_fork();


  if (pid > 0){  /* parent */

    assert(close(pipefd[0]) != -1);
    assert(close(pipefd[1]) != -1);  

    /*
    Stop reading the file when there is no more word
    */
    while(scanf("%s", &line[num_chars]) != EOF){
        /*
        stop store the word in array and 
        move to the print_line function to 
        print the word
        */
      num_chars ++;

    }
    if(num_chars >= 200){
      result = 0;
      printf("Long enough!\n");   
      
    }else{
      result = 1;
      printf("Too short!\n");
    }


      

  }else {
    if (pid == 0) {  /* child */  


    assert(close(pipefd[0]) != -1);
    assert(close(pipefd[1]) != -1);  

    execle("/user/bin/wc", "-w", NULL, environ);


    }
  }





  return result;
}



