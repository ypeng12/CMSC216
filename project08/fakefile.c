/*

Yuliang Peng CMSC216 Sections: 0205
Project 08
I pledge on my honor that I have not given or received any
unauthorized assistance on this project.

*/


#include <stdlib.h>
#include <string.h> 
#include <stdio.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/stat.h> 
#include <errno.h>
#include <unistd.h>
#include <sysexits.h>
#include <assert.h>
#include <err.h>
#include "fakefile.h"
#include "safe-fork.h"
#include "fakefile-datastructure.h"
#include "split.h"
#include "make-target.h"

#define MAX_LINE_LENGTH 1000

extern int errno ;


/*
This funiction will return the information about
files in the filesystem given their filenames. 
I need to detremine the target by using stat()
*/

int exists(const char filename[]){

	/*
	Set the errno to 0
	*/
	errno = 0;

	if (filename != NULL){
		const char *fd = filename;
		struct stat buf;

		/*
		If stat() returns -1 then need to set wether errono
		is ENOENT
		*/

		if ( stat(fd, &buf) == -1){

			/*
			if errno == ENOENT then means the files with name 
			path does not exite otherwise then means the files
			exit
			*/

			if (errno == ENOENT){
				return 0;
			}else{
				return -1;
			}		
		}else{
			return 1;
		}
	}else{
		return 0;
	}	
}

/*
This is older function will return 1 if filename1 and
filename 2 is exit and filename is older than filename2
*/

int is_older(const char filename1[], const char filename2[]){
		
		struct stat buf1;
		struct stat buf2;

		int stat1 = 0;
		int stat2 = 0;


		/*
		need to make sure filename1 and filename2 are not NULL
		*/

		if (filename1 != NULL && filename2 != NULL){

			/*
			Using stat() to get status and .st_mtime
			is to know when make up and smaller is older
			*/

			stat1 = stat(filename1, &buf1);
			stat2 = stat(filename2, &buf2);
		
			if (stat1 != -1 && stat2 != -1 ){
				if ( buf1.st_mtime < buf2.st_mtime ){
					return 1;
				}
			}
		}else{
			return 0;
		}
	return 0;

}


/*

This function is store a Fakefile variable in dunamically
allocate memory. open the fine with name filename and read 
the components of a fakefile from it. store the components in
the allocate Fakefile and return the memory

*/

Fakefile *read_fakefile(const char filename[]){

	/*
	buff is for read lines and MAX_LINE_LENGTH is 1000
	words is the array for split
	*/

	char  buff[MAX_LINE_LENGTH] = "";    
	char ** words;
	int num = 0;
	FILE *fp;
	int count = 0;
	
	if (exists(filename)){

		/*
		use malloc to make allocate memory I will use
		linkedlist to store the data.
		*/

		Fakefile *filesystem = 
			(Fakefile* )malloc(sizeof( Fakefile));

		
		/*
		Initialize each pointers
		*/
	 
		filesystem->next = NULL;
		filesystem->prev = NULL;
		filesystem->head = NULL;
		filesystem->tail = NULL;
		filesystem->type = 0;
		filesystem->command = NULL;

		/*
		open the file and read each lines by using 
		fgets.
		*/

		fp = fopen(filename, "r");
		count  = 0;

		while ( fgets(buff, MAX_LINE_LENGTH, fp) ){
			
			words = split(buff);
			num = 0;

			/*
			the words is array and get from split
			read each lines and store into the linkedlist 
			*/

			while ( words[num] != NULL ){

				/* make new_node and use it to store 
				command is for each words in the code
				*/

				Fakefile *new_node = malloc(sizeof(*new_node));	


				new_node->command = malloc(1 + strlen(words[num]));
				strcpy( new_node->command, words[num] );

				/*
				store the new_node by none order
				store the new_node to the tail

				the type of the pointer is to let us 
				know where is the words in the line
				(position start from 0)

				and need to free the words for no leak memory
				*/

				/*
				Case 1: add to the head
				*/

				if ( filesystem->head == NULL ) {
				

					filesystem->head = new_node;
					filesystem->head->next = NULL;
					filesystem->head->prev = NULL;
					filesystem->tail = new_node;
					new_node->type = 0;
					free(words[num]);

				/*  
				Case 2: add to the tail
				*/	

				}else {

					filesystem->tail->next = new_node;
					new_node->prev = filesystem->tail;
					new_node->next = NULL;
					filesystem->tail = new_node;
					new_node->type = num;	
					free( words[num] );
					
				}			
				num ++;
		
			}

			/*
			Need to free the words 
			*/ 

			free(words);
			count ++;
					
		}
		
		fclose(fp);
		return filesystem;

	}else{
		return NULL;
	}
}


/*
if the fakefile is NULL of is rule_nun is not a valid rule
number for fakefile this fuction return nothing but if 
not will read from the likedlist and print exact same
as orginal one.
*/

void print_fakefile(Fakefile *const fakefile){

	Fakefile *curr;
	int count;


	if (fakefile != NULL){

		curr = fakefile->head;
		count = 0;

		/*
		read the linked list and print it 
		*/ 

		while((curr != NULL)){

			if (curr->type == 0  ){

				count ++;
				/* need tab and second place */
				if ( count % 2 == 0 ){
					
					printf( "\n\t%s",curr->command );
					
				/* new line and first place */

				}else if ( curr->prev != NULL && count %2 == 1 ){

					printf( "\n\n%s:",curr->command );

				/* first place */

				}else{	
					printf( "%s:",curr->command );
				}
			}else {
				
				printf(" ");
				printf("%s",curr->command);
				
			}

			curr = curr->next;
		}
		printf("\n");

	}
}


/*
This function will serach for a rule in its parameter fakefile
and if the target exit in the likedlist then return its number and 
if not return -1
*/

int lookup_target(Fakefile *const fakefile, const char target_name[]){

	int result = -1;
	int count = 0;
	Fakefile *curr;


	if (fakefile != NULL && target_name != NULL){
	
		curr = fakefile->head;

		/*
		read the linked list by using while loop

		the curr->type == 0 will find the first command in
		each lines and the count %2 will find the command name
		(likes main.x ) by using count. 

		the result will return which target name's line 

		*/

		while((curr != NULL) ){
			
			if ( curr->type == 0){
				
				if (count % 2 == 0 ){

					result ++;
					
					/*
					if find the targert name in the linkedlist 
					then return the size of the dependencies
					*/

					if ( strcmp(curr->command, target_name) == 0 ){	

						return result;

					}
				}	
				count ++;
			}
			curr = curr->next;
		}	
	}else {
		return -1;
	}
	return -1;

}



/*
This function will return how is the size of the dependencies
in the command.
if fakefile and rule_num is not valid then return -1
otherwise return the size of the dependencies

*/

int num_dependencies(Fakefile *const fakefile, int rule_num){

	Fakefile *curr;
	int result = 0;
	int count = 0;


	if ( fakefile != NULL && rule_num >= 0 ){
		curr = fakefile->head;


		/*
		this will use count to get where where is the 
		target is and find it in linkedlist
		the (count- 1) /2  == rule_num will find (gcc)
		and the curr->prev->type return the size of dependencies
		the count % 2 == 1 will find the line 1, 3, 5
		if in the code it's  gcc
		main.x -o ...

			gcc ...

		will return the size of the dependencises.
		*/

		while(( curr != NULL) ){
			
			if ( curr->type == 0){

				if ( count % 2 == 1 && ( count- 1 ) /2  == rule_num){
					result = curr->prev->type ;	
					return result;
				}
				count ++;
			}
			curr = curr->next;
		}

	}else{
		
		return -1;
	}
	
	return result;
}



/*
This function will return the command by using rule_num and 
dependency_num to find the positions.
*/

char *get_dependency(Fakefile *const fakefile, int rule_num, 
	int dependency_num){

	Fakefile *curr;
	char *result = "";
	int count = 0;


	if (fakefile != NULL && rule_num >= 0 && dependency_num >= 0){
		curr = fakefile->head;

		/* read the linkedlis */

		while((curr != NULL) ){

			if ( curr->type == 0 ){
				count ++;
			}

			/*
			This will use count, rule_num and dependency_num to find 
			the target command
			
			*/

			if (count % 2 == 1 && ( count - 1 ) / 2  == rule_num &&  
				( curr->type - 1 )  == dependency_num){
				
				result = curr->command;
				return result;	
				
			}
			curr = curr->next;
		}

	}else{
		return NULL;
	}		
	return result;
}


/*
This do action will perform the action of the rule with 
number ruble_num in its parameter fakefile and if the 
command exit do action will return exit status and action
returned when performend
*/

int do_action(Fakefile *const fakefile, int rule_num){


	Fakefile *curr;
	Fakefile *run_node;
	int count = 0;
	char  command_line[MAX_LINE_LENGTH] = "";
	int num2 = 0;
	int exit_status ;

	/* make child_pid for fork */

	pid_t child_pid;

	if (fakefile != NULL && rule_num >= 0){
		
		curr = fakefile->head;
		
			while((curr != NULL)  ){
				
				/*  use type and  count to find the first command
				in the lines
				*/

				if ( curr->type == 0 ){
					
					if ( count % 2 == 1 && (count) / 2  == rule_num ){
						
						/*
						need use strcat to puts the command into the 
						char command_line for the split() and get
						array
						*/

						run_node = curr;

						/*
						this is for the case for the first node 
						becasue I need to use run_node->type > 0 in
						while loop but the first node's type is 0
						*/

						strcat(command_line, run_node->command);
						strcat(command_line, " ");

						run_node = run_node->next;

						/*
						The run_node->type > 0 means run unitill be new line
						in command
						*/

						while ( run_node != NULL && run_node->type > 0 ){
							
							strcat(command_line, run_node->command);
							strcat(command_line, " ");
							run_node = run_node->next;

						}

						if ( command_line != NULL){

							/* 
							Using split() to get array and 
							split_action is the array for the command
							*/

							char ** split_action = split(command_line);

							/*
							use safe-fork() for child and parent
 							*/

							child_pid= safe_fork();
							
							/* parent */

							if (child_pid > 0){
								
								/* use the wait for child *
								this will let child run before parents
								parents will not run untill child finished
								*/

								wait(&exit_status);

								/* if the split_action is valid and 
								have a valid command or not */

								if (split_action[1] == NULL){
									return -1;
								}else{
									return exit_status;
								}	
							}else{

								/* this is the child code */	

								if (child_pid == 0){
									
									/* use execvp to let child run the program */

									execvp(split_action[0],split_action);
									
									/*exit -1 for no more run */

									exit(-1);
									
								/* return error if not valid */

								}else if ( child_pid < 0 ){
									err(EX_OSERR, "fork error");
								}
							}
							/* use while loop to clean the split_action
							because it's array 
							*/

							while(ARRSIZE(split_action) > num2){
								free(split_action[num2]);
								num2++;
							}
							free(split_action);							
						}
					}
					count ++;
				}
				curr = curr->next;
			}	
	
	}else{
		return -1;
	}

	return exit_status;

}

/*
this function will print the compaonests of its
parementer fakefile

the rule need to print in same order
and the rule will print in two lines 
the target name will start at the beginning of 
the line
*/

void print_action(Fakefile *const fakefile, int rule_num){


	Fakefile *curr;
	Fakefile *run_node;
	char  command_line[MAX_LINE_LENGTH] = "";
	pid_t child_pid;
	int count = 0;
	int exit_status ;
	int count2 =0;
	int num = 0;
	int num2 = 0;

	if (fakefile != NULL && rule_num >= 0){
		
		curr = fakefile->head;
		

			while((curr != NULL)  ){
					
				if ( curr->type == 0){
					/*
					use count and rule_num to find where need to read
					*/
					if (count % 2 == 1 && (count) / 2  == rule_num){
						
						
						/*
						need use strcat to puts the command into the 
						char command_line for the split() and get
						array
						
						this is for the case for the first node 
						becasue I need to use run_node->type > 0 in
						while loop but the first node's type is 0
						*/

						run_node = curr;
						strcat(command_line, run_node->command);
						strcat(command_line, " ");
						run_node = run_node->next;

						/*
						The run_node->type > 0 means run unitill be new line
						in command
						*/

						while (run_node != NULL && run_node->type > 0 ){
							count2 ++;
							strcat(command_line, run_node->command);
							strcat(command_line, " ");
							run_node = run_node->next;

						}
						if ( command_line != NULL ){

							/* use splic to make the command to array */

							char ** split_action = split(command_line);							
					
							child_pid= safe_fork();
			
							/* parent */

							if (child_pid > 0){
								
								/* print the array follow the request */

								while(split_action[num] != NULL ){
									printf("%s",split_action[num]);
									if (split_action[num + 1] != NULL){
										printf(" ");
									}	
									num ++;
								}	
								printf("\n");	
							
								wait(&exit_status);

							}else{
								/* this is the child code */	
								if (child_pid == 0){
																						
									exit(-1);
									
																									
								}else if (child_pid < 0){
									err(EX_OSERR, "fork error");
								}
							}
							
							/*
							free the split_action
							*/

							while(ARRSIZE(split_action) > num2){
								free(split_action[num2]);
								num2++;
							}
							free(split_action);
						}
					}
					count ++;
				}
				curr = curr->next;
			}
	free(curr);
	
	free(run_node);
	
	}
}

/* clear the fakefile */

void clear_fakefile(Fakefile **const fakefile){
	
	/* need to rereference the fakefile to linkedlist */
	
	Fakefile *filesystem = *fakefile;
	Fakefile *curr, *store;
	store = NULL;
	curr = filesystem->head;
	/*
	delete the element by using free
	*/
	while ( curr != NULL){
		store = curr->next;
		free(curr->command);
		free(curr);
		curr = store;
	}



	

}
