#include <stdlib.h>
#include <string.h> 
#include <stdio.h>
#include "ournix.h"


/*
Yuliang Peng CMSC216 Sections: 0205
UID 118495965 Project 06

I pledge on my honor that I have not given or received any
unauthorized assistance on this project.

This program is doing the kind of the same thing with the terminal.
It will develop new operating system and the durning developement is 
"Ournix", it will similate of the filesystem cooperating system.
mkfs for initialize
touch for files
mkdir for directory
ls for print data
cd for remove into the directory
rmfs for delete all data
rm for delete one name
pwd for print out the position

*/





/* Define the filesystem->current_dir is NULL or not */

unsigned int is_empty(const Ournix filesystem);


/*
This functions is for initialize all. this functions 
will be use when make new filesystems
*/

void mkfs(Ournix *const filesystem) {
 
	if (filesystem != NULL) {
		/*
			Using malloc to make new_node for initialize
			filesystem->current_dir should always be the 
			root of each likedlist and 
			filesystem->root should always be the "/" which
			means not change 
		*/
		

		Node *new_node = malloc(sizeof(*new_node));

		filesystem->current_dir = new_node ;
		filesystem->root = new_node;
		/*
		Need to initialize the pointer and
		timestamp and type will set to 0 
		the type is for find it's direcotry or files
		*/

		filesystem->current_dir->next= NULL;
		filesystem->current_dir->parent= NULL;
		filesystem->current_dir->children= NULL;
		filesystem->current_dir->prev= NULL;
		filesystem->current_dir->name= NULL;
		filesystem->current_dir->timestamp = 0;
		filesystem->current_dir->type = 0;


	}
}   

/*
Return 1 if the filesystem is empty
*/

unsigned int is_empty(const Ournix filesystem) {
	return (filesystem.current_dir->children == NULL);
}


/*
This function is to insert the files to the likedlist. 
It has a effect to create a file, if it does not already 
exit or to updata the timestamp of a file if it does 
already exit 

This function will is sorted insert
*/


int touch(Ournix *const filesystem, const char name[]){
	/*
	Make fileds, 
	the result for the last number to return
	the curr is  filesystem->current_dir->children
	the previous_node is the previous node before curr
	the target is NULL and works in when has same name in
	the filesystems.
	I will call the insert element as element
	
	*/

	int result = 0;
	Node *curr;
	Node *previous_node;
	int dir = 0;
	Node *target = NULL;



	/* Checking if inputs are non-NULL */
	if (filesystem != NULL && name != NULL ) {

		previous_node = NULL;
	
		
		curr = filesystem->current_dir->children;
		/* Traverse the list until a higher priority is found or 
		   stop if the list empty. */
		

		dir = strstr(name, "..") == NULL
			&& strstr(name, ".") == NULL && 
			strstr(name, "/") == NULL ;
						
		if (dir == 0){
			
			return 1;

		}				
		while (curr != NULL && strcmp(curr->name, name)<0){
			previous_node = curr;
			result = 1;
			curr = curr->next;
		}
			
		
		/* Check if the paramater priority is already in the list or not. */
		if (is_empty(*filesystem) || curr == NULL || 
			strcmp(curr->name, name) > 0) {
			
			Node *new_node = malloc(sizeof(*new_node));

			/* Check if dynamic allocation was succesfull. */
			if (new_node != NULL) {
				new_node->name = malloc(1 + strlen(name) );
				strcpy(new_node->name, name);
				
				/* Set result to one to confirm succesfull node creation. */
				result = 1;
				
				/* There are 2 cases for inserting a new node into
				   the ordered doubly linked list.*/

				/* Case 1: empty list */
				if (is_empty(*filesystem) ) {

					filesystem->current_dir->children = new_node;
					filesystem->current_dir->children->next = NULL;
					filesystem->current_dir->children->prev = NULL;
					filesystem->current_dir->children->parent = 
						filesystem->current_dir;
					filesystem->current_dir->children->type = 0;

				/*  
				Case 2: if the previous_node is NULL most will be 
				when the parent is not NULL
				*/					
				}
				else if ( previous_node == NULL){
				
 					filesystem->current_dir->children = new_node;
					filesystem->current_dir->children->next = curr;
					filesystem->current_dir->children->prev = NULL;
					filesystem->current_dir->children->parent = 
						filesystem->current_dir;
					filesystem->current_dir->children->type = 0;
					
				}
				
				/* Case 2: end of the list */
				else if (curr == NULL) {
					
					new_node->prev= previous_node;
					new_node->next= NULL;
					new_node->parent = filesystem->current_dir;
					new_node->children = NULL;
					previous_node->next = new_node;			
					new_node->type = 0;
					
				/* case 4: general (middle of list) case */
				}else{
		
					new_node->prev= previous_node;
					new_node->next= curr;
					curr->prev= new_node;
					new_node->children = NULL;
					new_node->parent = filesystem->current_dir;
					previous_node->next = new_node;		
					new_node->type = 0;					
				}
			}
		}
		/*
		if the silesystems already has the same name
		and if so then add the timestamp by 1
		*/
		while (curr != NULL && target == NULL && 
		(strcmp(curr->name, name) )== 0) {
			
			if ((strcmp(curr->name, name) )== 0 ) {

				target = curr;			
				curr->timestamp ++;		
				result = 1;
			
			}
		}	
	}
	return result;

}

/*
This functions is works to add(insert) the subdirectory from 
dirctory is not exite name before
*/

int mkdir(Ournix *const filesystem, const char name[]){
	
	/*
	Make fields
	the result for the last number to return
	the curr is  filesystem->current_dir->children
	the previous_node is the previous node before curr
	the target is NULL and works in when has same name in
	the filesystems.
	I will call the insert element as element
	In this mkdir the curr->type will be 1
	*/
	int result = 1;
	int dir = 0;
	Node *curr;
	Node *previous_node;
	Node *target = NULL;
	

	/* Checking if filesystem and name are non-NULL */
	if (filesystem != NULL && name != NULL) {

		previous_node = NULL;
		curr = filesystem->current_dir->children;


		dir = strstr(name, "..") == NULL
			&& strstr(name, ".") == NULL && 
			strstr(name, "/") == NULL ;
						
		if (dir == 0){
			return 1;
		}	

		/* Traverse the list until a bigger elemnt is found or 
		   stop if the list empty. */
		while (curr != NULL && strcmp(curr->name, name) < 0){
			previous_node = curr;
			result = 1;
			curr = curr->next;
		}
			
		
		/* Check if the paramater priority is already 
			in the list or not. */
		if (is_empty(*filesystem) || curr == NULL || 
			strcmp(curr->name, name) > 0) {
			
			Node *new_node = malloc( sizeof(*new_node) );

			/* Check if dynamic allocation was succesfull. */
			if ( new_node != NULL ) {
				new_node->name = malloc( 1 + strlen(name));
				strcpy(new_node->name, name);
			
				/* Set result to one to confirm succesfull 
					node creation. */
				result = 1;
				
				/* There are 4 cases for inserting a new node into
				   the ordered doubly linked list.*/

				/* Case 1: empty list */
				if ( is_empty(*filesystem) ) {
					
					filesystem->current_dir->children = new_node;
					filesystem->current_dir->children->next = NULL;
					filesystem->current_dir->children->prev = NULL;
					filesystem->current_dir->children->parent = 
						filesystem->current_dir;
					filesystem->current_dir->children->type = 1;
					
				/* 
					Case2: if previous_node == NULL (have
					parent)
				*/
				}else if ( previous_node == NULL ){
				
 					filesystem->current_dir->children = new_node;
					filesystem->current_dir->children->next = curr;
					filesystem->current_dir->children->prev = NULL;
					filesystem->current_dir->children->parent = 
						filesystem->current_dir;
					filesystem->current_dir->children->type = 1;
				}
				
				/* Case 3: end of the list */
				else if ( curr == NULL) {
			
					new_node->prev= previous_node;
					new_node->next= NULL;
					new_node->parent = filesystem->current_dir;
					new_node->children = NULL;
					previous_node->next = new_node;
					new_node->type = 1;
							
				/* case 4: general (middle of list) case */
				}else{
					
					new_node->prev= previous_node;
					new_node->next= curr;		
					curr->prev= new_node;
					new_node->children = NULL;
					new_node->parent = filesystem->current_dir;
					previous_node->next = new_node;
					new_node->type = 1;
								
				}
			}
		}
		/*
		When the directory already has same name nothing will
		happen
		*/
		while ( curr != NULL && target == NULL && 
		( strcmp(curr->name, name)) == 0) {
			
			if (( strcmp(curr->name, name)) == 0 ) {
				result = 1;
				target = curr;			
				curr->type = 1;		
			}
		}	
	}
	return result;
}


/*
This function change the current directory of it's Ournix paramenter
it will always have some mechanism ot keep track of its current locaiton
at all time
*/

int cd(Ournix *const filesystem, const char name[]){

	int result = 1;
	Node *curr;

	/*
	Check if the name and filesystem is not NULL
	*/
	if (name != NULL && filesystem !=  NULL){

		curr = filesystem->current_dir->children;

		/*
		if the name is empty or single period then return 1
		nothing else will do
		*/ 

		if ( strcmp(name, ".") == 0  || strcmp(name, "") == 0 ){
			return 1;
		
		/*
		if the name is ".." double periods then will change the 
		current_directory to that parent's one
		*/

		}else if (strcmp(name, "..") == 0){
			filesystem->current_dir = filesystem->current_dir->parent;

		/*
		if the name is "/"  then will change current directory to be 
		the root dirctory
		*/		

		}else if (strcmp(name, "/") == 0){
			filesystem->current_dir = filesystem->root;
			
		}else{

			/*
			Check is there filesystem has the same element's name 
			*/ 

			while ( curr != NULL && (strcmp(curr->name, name) != 0)){		
				curr = curr->next;			
			}

			/*
			If found the same name in that directory then need to 
			check it's files or dirctory
			when curr->type == 1 then it's dirctory and need have
			change but else will do nothing
			*/		

			if ( curr != NULL && strcmp(curr->name, name) == 0){
				
				/*
				if it's dirctory then need to change the current
				directory to that new element if not do notging 
				*/
				if ( curr->type == 1 ){
					filesystem->current_dir = curr ;
				}else{
					curr = curr->next;	
				}
			}
		}
	}else{
		return 0;
	}
	return result;
}

/*
This function effect is to list the files and subdirectorys of the 
current dirctory or the files and subdirectoy of its argument of to 
list just its argument if that is a file
*/

int ls(Ournix *const filesystem, const char name[]){

	int result = 1;

	/*check if the filesystem is not NULL */

	if (filesystem !=NULL ){

		Node *curr = filesystem->current_dir->children;
		Node *curr2 = filesystem->current_dir;	
		Node *curr3 = filesystem->root->children;
		Node *new_order;
		
		/*
		if  the element has the name of "." or empty then will
		print out the names of all files and subdirections in that 
		dirctory
		*/

		if (strcmp(name, ".") == 0 || strcmp(name,"") == 0 ) {
			
			while (curr != NULL ){
				if (curr->type == 1){
					printf("%s/\n", curr->name);	
				}else if (curr->type == 0){
					printf("%s\n",  curr->name);
				}
				curr = curr->next;							
			}				
		}
		/*
		if  the element has the name of ".." then will
		print out the names of all files and subdirections in that 
		current dirctory
		*/

		else if (strcmp(name, "..") == 0 ) {

			new_order =  NULL;


			/*
			this new_order will helps to change the
			order of the names
			*/

			while (curr2 != NULL  ){

				Node *new_node = malloc(sizeof(*new_node));
				new_node->name = malloc(1 + strlen(name) );
				strcpy(new_node->name, curr2->name);
				new_order = curr2->next;
				new_node->next = new_order;	
				new_order = new_node;

				if (curr2->prev == NULL){
					curr2 = NULL;
				}else{
					curr2 = curr2->prev;
				}							
			}

			/*
			print the new_order 
			*/

			while (new_order != NULL ){
				if ( new_order->type == 1 ){
					printf("%s/\n", new_order->name);	
				}else {
					printf("%s\n",  new_order->name);
				}
				new_order = new_order->next;		

			}
			if ( curr2 == NULL && new_order == NULL ){
				return 1;
			}					
		}
		/*
		if  the element has the name of ".." then will print
		out the names of all files and subdirections in that
		root directory
		*/
		else if ( strcmp(name, "/") == 0 ){
			
			new_order =  NULL;
			while ( curr3 != NULL ){

				if ( curr3->type == 1 ){
					printf("%s/\n", curr3->name);	

				}else if ( curr3->type == 0){
					printf("%s\n", curr3->name);
				}
				curr3 = curr3->next;							
			}
		}else {
			while(curr != NULL && strcmp(curr->name, name) != 0 ){
				curr = curr->next;	
			}

			/*
			if the element name alrady exits and it's files then return 
			that name and the timestamp
			*/

			if ( curr != NULL && strcmp(curr->name, name) == 0 && 
				curr->type == 0 ){
				
					curr->timestamp ++;
					printf("%s %d\n", curr->name,curr->timestamp )	;

			}
						
			/*
			if the element name alrady exits and it's directory then return 
			names of all files and subdirections in that current directory
			*/

			if (curr != NULL && strcmp(curr->name, name) == 0 
				&& curr->type == 1) {
				
				curr = curr->children;

				while ( curr != NULL ){
					if ( curr->type == 1){

						printf("%s/\n", curr->name);	
					}else if ( curr->type == 0){
						printf("%s\n",  curr->name);
					}
					curr = curr->next;								
				}				
			}
		}
	}
	return result;
}

/*
This function will return where the element is works
*/ 

void pwd(Ournix *const filesystem){

	/*check if filesystem is not NULL */

	if (filesystem != NULL){
		Node *curr = filesystem->current_dir;
		Node *new_order;

		new_order =  NULL;
		/*new order will help the order */

		while ( curr->parent != NULL  ){

			Node *new_node = malloc( sizeof(*new_node) );
			new_node->name = malloc( 1 + strlen(curr->name) );
			strcpy(new_node->name, curr->name);

			new_node->parent = new_order;
			new_order = new_node;
			curr = curr->parent;	
							
		}

		if (new_order == NULL ){
			printf("/");
		}
		while (new_order != NULL ){
			printf("/");
			printf("%s",new_order->name);
			new_order = new_order->parent;		
							
		}	
		printf("\n");
		free(new_node->name);
		free(new_node);
	}
}

/*
This will delete all elements in filesystem
*/
void rmfs(Ournix *const filesystem){
	/*
	check is filesystem is NULL
	*/

	if( filesystem != NULL ){
		Node *curr, *store;
		store = NULL;
		curr = filesystem->root->children;
		/*
		delete the element by using free
		*/
		while ( curr != NULL){
			store = curr->next;
			free(curr->name);
			free(curr);
			curr = store;
		}
		if (curr == NULL){
			free(filesystem->root);
		}

		
	}
}

/*
remove the element in the filesystem
*/

int rm(Ournix *const filesystem, const char name[]){

	int result = 1;
	Node *curr;
	Node *previous_node = NULL;

	/*check if filesystem and name is not NULL */

	if ( filesystem != NULL && name != NULL ){

		curr = filesystem->current_dir->children;

		while (curr != NULL && strcmp(curr->name, name) != 0){
			previous_node = curr;
			curr = curr->next;
		}

		/* Case 1: front */
		if (curr->prev == NULL){

			filesystem->current_dir->children = 
				curr->next;
			curr->next->prev = NULL;
			curr->next->parent = filesystem->current_dir;
			previous_node = NULL;
			free(curr->name);
			free(curr);
		/*Case 2 end */
		}else if (curr->next == NULL){
			previous_node = curr->prev;
			previous_node->next = NULL;
			free(curr->name);
			free(curr);
		/*case 3 ususal case */
		}else{
			curr->next->prev = previous_node;
			previous_node->next = curr->next;
			free(curr->name);
			free(curr);
		}
	}else{
		return 0;
	}
	return result;
}


