/*
Yuliang Peng CMSC216 Sections: 0205
Project 02
I pledge on my honor that I have not given or received any
unauthorized assistance on this project.
*/

#include <stdio.h>

/* 
max len of input & output lines is 999
*/ 
#define MAX_INPUT 999  

/*
This checklength.c needs to read the line, store each 
line and then print out, the max for storing data is 999
and when printing, the line is over the 80 then print "X",
more detail will explain later.
*/

void print_line(char line[], unsigned int num_chars);

int main(void) {
  char line[MAX_INPUT];
  unsigned int num_chars = 0;   

  /*
  Stop reading the file when there is no more word
  */
  while(scanf("%c", &line[num_chars]) != EOF){
      /*
      stop store the word in array and 
      move to the print_line function to 
      print the word
      */
     
      if (line[num_chars] == '\n'){
        print_line(line, num_chars);
        /*
        Need to reset the num_chars because 
        the array just only can store one line
        */
        num_chars = 0;
      }else{
        /*
        The num_chars needs to increase 1 for each 
        character when didn't find the "\n"
        */
        num_chars++;
      }
  }
  return 0;
}


/*
This print_line() function is print the line length and the string
when the line length is over the 80, then needs to print X before 
the number of the line length
*/
void print_line(char line[], unsigned int num_chars){

  unsigned int num = 0;

  /*
  When the num_chars (the line lenght) is over the 80
  then print "X__" (_ means space) if not just print 
  three space "___". 
  */
  if (num_chars > 80 ){ 
    printf("X %3d: ", num_chars);
  }else{
    printf("  %3d: ", num_chars);
  }

  /*
  This for loop to print out the string which in the array
  */
  for (num = 0; num <= num_chars ; ++num) {
    printf("%c", line[num]);
  }
}