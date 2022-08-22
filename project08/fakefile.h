#if !defined(FAKEFILE_H)
#define FAKEFILE_H

/* (c) Larry Herman, 2022.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* DO NOT MODIFY THIS FILE OR YOUR CODE WILL NOT COMPILE ON THE SUBMIT
   SERVER */

#include "fakefile-datastructure.h"

/* this macro ONLY works right in the scope where an array is DECLARED */
#define ARRSIZE(arr) ((int) (sizeof(arr) / sizeof((arr)[0])))

int exists(const char filename[]);
int is_older(const char filename1[], const char filename2[]);
Fakefile *read_fakefile(const char filename[]);
int lookup_target(Fakefile *const fakefile, const char target_name[]);
void print_action(Fakefile *const fakefile, int rule_num);
void print_fakefile(Fakefile *const fakefile);
int num_dependencies(Fakefile *const fakefile, int rule_num);
char *get_dependency(Fakefile *const fakefile, int rule_num,
                     int dependency_num);
int do_action(Fakefile *const fakefile, int rule_num);
void clear_fakefile(Fakefile **const fakefile);

#endif
