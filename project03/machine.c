/*
Yuliang Peng CMSC216 Sections: 0205
Project 04
I pledge on my honor that I have not given or received any
unauthorized assistance on this project.
*/
#define true 1
#define false 0

typedef unsigned short boolean;
/*
This project is reading 4 bytes instruction words from processor
there is some functions to read and print, and determine the 
words is valid or not
*/

#include <stdio.h>
#include "machine.h" 

/*
this function will interpret the parameter as a Nelovo instructios.
Using the bits operations to exact the fields descriptions and 
operations. and print the intructions on a single outline
*/

unsigned short print_instruction(Mach_word instr){

  /*
  Using the bits operations, there are 5 different types 
  and it's opcode, reg1, reg2, reg3, memory_address.
  */

  unsigned short opcode =  instr >> 26 ;
  unsigned short reg1 = ( instr >> 22 ) & 0xf;
  unsigned short reg2 = ( instr >> 18 ) & 0xf;
  unsigned short reg3 = ( instr >> 14 ) & 0xf;
  unsigned short memory_address = ( instr & 65535);


  /*
  In order to use less memory, I tried to use array to store the
  the name for the intructions' name and use it to print out
  I will print the name by using  array[opcode][0]
  */

  char * array[23][4] = {
    {"halt"}, {"add"},{"sub"},{"mul"},{"div"},{"rem"},{"neg"},
    {"and"},{"or"},{"not"},{"eql"},{"neg"},{"lt"},{"gt"},
    {"le"}, {"ge"},{"test"},{"move"},{"li"},{"lw"},
    {"sw"},{"read"},{"prt"}
  };

  /*
    Use the is_valid function to know the instructure is
    valid or not, if not valid return 0
    if valid should print and then return 1
  */

  if( !is_valid(instr) ){
    return false;

  }else{

    /*
    Print the instructions
    Use switch statment to find the opcode, There are 6 cases
    By making cases could solve memory and if I making less cases
    the code will be complicate

    1: Halt, just only print the "halt"
    2: Need to print Reg1, Reg2, Reg3
    3: Need to print Reg1, Reg2
    4: Need to print Reg1
    5: Need to print Reg1, Memory address, and need some
      zero before the number , "%05d"
    6: Li, Need to print Reg1, Memory address but no 
      need to print the zero before the number, "%d"  
    */

    switch( opcode ){
    
    /* 
    1: Halt, just only print the "halt"
    when the opcode value equal to zero
    need to print "halt" 
    */

    case HALT:

      printf( array[opcode][0] );
      
      break;

    /*
    2: Need to print Reg1, Reg2, Reg3
    need to be like "add R01 R01 R01"
    */

    case ADD:
    case SUB:
    case MUL:
    case DIV:
    case REM:
    case AND:
    case OR:
    case EQL:
    case NEQ:
    case LT:
    case GT:
    case LE:
    case GE:

      printf( "%s\tR%01d\tR%01d\tR%01d", 
            array[opcode][0], reg1, reg2, reg3 );
      
    break;

    /* 
    3: Need to print Reg1, Reg2 
    need to be like "neg R01 R01 "
    */

    case NEG:
    case NOT:
    case MOVE:
      printf("%s\tR%01d\tR%01d", array[opcode][0], reg1, reg2);
      
    break;

    /*  
    4: Need to print Reg1
    need to be like "read R01"
     */

    case READ:
    case PRT:
      printf("%s\tR%01d", array[opcode][0], reg1);
      
    break;


    /* 
    5: Need to print Reg1, Memory address
    need to be like "test R01 00215"
    */

    case TEST:
    case LW:
    case SW:
      printf("%s\tR%01d\t%05d", array[opcode][0], 
        reg1, memory_address);
      
    break;

    /*
    6: Li, Need to print Reg1, Memory address
    Special case, no limit for memory  
    need to be like "li R01 215"   
    */

    case LI:
      printf("%s\tR%01d\t%d", array[opcode][0], 
        reg1, memory_address);     
    break;

    }
    return true;
  }
}

/*
This function name is disassemble, it will converts machine
language to assemble language.
It will read the program array and find the instruction,
and follow the max_addr then print out the assemble 
language.
*/

unsigned short disassemble(const Mach_word program[],
                           unsigned short max_addr){
  
  /*
  Make fieds 
  - the dis is a boolean and it's for return is there 
    a dissemble number or not
  - the i is use in for loop
  - the start_num is using to print the hexadecimal number
  */
	boolean dis = false;
	int i;
	unsigned short start_num;

	i=0;
	start_num=0;
	
  /*
    This if statment is use to find the max_addr
    is valid or not and the program is null or not
  */

  if(max_addr >= 0 && max_addr <=  NUM_WORDS && program != NULL) {

    /*
      This for loop is find how many times need to 
      read the number, the max_addr/4 + 1 is 
      comes from 0 bytes, 4 bytes, 8 bytes ...
      and if the max_addr is 16 then it's 5 times
    */

		for (i = 0; i < max_addr/4 + 1; i++) {

      /* 
      Checks if every instruction is valid by 
      using the is_valid functions
      */

      if(is_valid(program[i])){

        /*
          if the program is valid, then need to
          let the "dis" be true and then print out
          the hexadecimal number by using print_instruction
          functions. the start_num is start as 0 and 
          also print the four-byte world of machine memory
          by adding +=4 each time
        */
        dis = true;
        printf("%04x: ", start_num);
        print_instruction(program[i]);
        printf("\n");
        start_num += 4; 
  
      }else{ 
            
        /*
        If not valid then return false
        */
        return 0;
      }
    }
  }
	return dis ;
}

/*
  This function name is is_valid, this function will 
  read the machine instruction and find it's valid or not
*/

unsigned short is_valid(Mach_word word){
	unsigned short opcode =  word >> 26 ;
  unsigned short reg1 = ( word >> 22 ) & 0xf;
  unsigned short reg2 = ( word >> 18 ) & 0xf;
  unsigned short reg3 = ( word >> 14 ) & 0xf;
  unsigned short memory_addr = ( word & 65535 );
	boolean valid = false;
    
  /*
  Make boolean fields, the modified_R13 is find is there 
  reg1 have R13 or not, the valid_memory_address is to find 
  the memory address is possible to divide by 4 or not
  the vali_opcode is to find the opcode is bigger 0 <= opcode <=23
  and r1_valid, r2_valid,r3_valid are trying to find the reg is 
  0 <= reg <=13
  the valid is the result for this function
  */
  boolean  modified_R13 = (reg1 == R13);
	boolean valid_memory_address = (memory_addr % 4 == 0);
  boolean vali_opcode =(opcode>= 0 && opcode <= 23);
	boolean r1_valid = (reg1 >= R0 && reg1 <= R13);
	boolean r2_valid = (r1_valid && (reg2 >= R0 && reg2 <= R13));
	boolean r3_valid = (r2_valid && (reg3 >= R0 && reg3 <= R13));


  /*
  Using if statment to find the opcode is valid or not
  and then use switch to find the instructure is valid
  or not
  */

  if(vali_opcode ){

    /*
    The switch statment have some cases.
    1: reg1, reg2, reg3 and need to modify the reg1 is not R13
    2: reg1, reg2 and need to modify the reg1 is not R13
    3: reg1 and need to modify the reg1 is not R13
    4: reg1 and don't need to modify the reg1 is not R13
    5: reg1, memory address and need to modify the reg1 is not R13 
      and the memory address can divide by 4
    6: reg1, memory address and need to modify the reg1 is not R13 
      no require for memory address
    7: reg1, memory addressand the memory address can divide by 4
    8: Halt nothing need

    */
    switch(opcode){

      /* 
      1: reg1, reg2, reg3 and need to modify the reg1 is not R13 
      */

      case ADD:
      case SUB:
      case MUL:
      case DIV:
      case REM:
      case AND:
      case OR:
      case EQL:
      case NEQ:
      case LT:
      case GT: 
      case LE:
      case GE:
        if(r3_valid && !modified_R13){
          valid = true;
        }
        break;

      /* 
      2: reg1, reg2 and need to modify the reg1 is not R13
      */

      case NEG:
      case NOT:
      case MOVE:
        if(r2_valid && !modified_R13){
          valid = true;
        }
        break;
      /*
      3: reg1 and need to modify the reg1 is not R13
      */

      case READ:
        if(r1_valid && !modified_R13){
          valid = true;
        }
        break; 

      /*
      4: reg1 and don't need to modify the reg1 is not R13
       special case, PRT
      */

      case PRT:
        if(r1_valid ){
          valid = true;
        }
        break;      

      /*    
      5: reg1, memory address and need to modify the reg1 is not R13 
      and the memory address can divide by 4, LW
      */

      case LW:
        if(r1_valid && !modified_R13 && valid_memory_address){
          valid = true;
        }
        break;
      
      /* 
      6:reg1, memory address and need to modify the reg1 is not R13 
      no require for memory address, Li
      */

      case LI:
        if(r1_valid && !modified_R13 ){
          valid = true;
        }
        break;
      
      /* 
      7: reg1, memory addressand the memory address can divide by 4 
      TEST, SW
      */

      case TEST:
      case SW:
        if(r1_valid && valid_memory_address){
          valid = true;
        }
        break;

      /* 
      8: Halt nothing need
      */

      case HALT:
        if (!modified_R13){
          valid = true;
        }
        break;
    }
  }
  return valid;
}

/*
This check_branches function will facus on the test instruction
it will find that instruction is valid or not
this function will read the program array and return the 
number. 
*/
short check_branches(const Mach_word program[], unsigned short max_addr){

  /*
  The i is use in for loop
  the valid_number is the result for return, -10 is just for case
  the count is for count how many not valid test
  the first_test to make sure is there test instructure
  */

  unsigned int i = 0;
  unsigned int count = 0;
  unsigned int  first_test = 0;
  short number = 0;
  short  valid_number =- 10;

  /*
  Using if statement to make sure is the amx_addr is not valid
  and program is  null, if so return -1
  */

  if(max_addr<0 && max_addr > NUM_WORDS && program == NULL){
    valid_number = -1;
  }else{

    /*
    Using for loop to make roop for reading the array
    need read opcode and memory_address
    */ 

    for (i = 0; i <= max_addr/4  ; i++) {
      
      unsigned short opcode =  program[i] >> 26 ;
      unsigned short memory_address = ( program[i] &65535);

      /*
      Use if statment to find when the instructure is test
      opcode is 16, and if so first_test will be true shows 
      there is test in this array
      */

      if(opcode == 16){

        first_test = 1;

        /*
        determine the test's memory_address is valid or not
        if can't divide by 4 or bigger than max_addr then 
        need to add count, the count is for counting the 
        times how many not valid test instructure
        */

        if(memory_address % 4 != 0 || memory_address > max_addr){

           count ++;

          /*
          This if statment will help to find out the first
          not valid test instructure and let the address be
          the valid_number.
          */

          if (count == 1){
            valid_number = number;
          }
        }
      }

      /*
      if there is no test in instructure or 
      all of the test insturcuture are valid
      then return 1
      */

      if( !first_test || count == 0){
        valid_number = 1;
      }
    
    /*
    Becasue it's 4 bytes that need add 4 to the number each times
    */
    number += 4;
    }
  }
  return valid_number;
} 


