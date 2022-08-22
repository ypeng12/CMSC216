/*
Yuliang Peng CMSC216 Sections: 0205
Project 02
I pledge on my honor that I have not given or received any
unauthorized assistance on this project.
*/
#include <stdio.h>
/* 
max # of columns to process 
*/
#define MAX_COLS 8   

/*
This tabexpand.c needs to read the line and find if the line
have tab or not, and calculate the line length, at last print 
the string 
*/
int main(void) { 
  unsigned int line_length = 0;
  unsigned char n;
  unsigned int i =0;
  /*
  Stop reading the file when there is no more word
  */
  while (scanf("%c", &n) != EOF ){
    /*
    when the line have tab then needs to add space
    */
    if ( n == '\t'){
        /*
        Using the for loop to add the space
        */
        for(i = 0; i < MAX_COLS - (line_length % MAX_COLS); i++) {
          printf(" ");
        }
        /*
        Need to calculate the line_length, the MAX_COLS is 8
        Using the mod to calculate the line_length
        */
        line_length += MAX_COLS - (line_length % MAX_COLS);
    /*
    If the character is '\n' then needs to reset the line_length
    */
    }else if (n == '\n'){
      printf("\n");
      line_length = 0;
    /*
    If character is not '\n' and '\t' then print the character
    and increase the line_length
    */
    }else {
      printf("%c", n);
      line_length++;
    }
  }
  
return 0;
}