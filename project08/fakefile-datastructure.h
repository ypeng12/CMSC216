#if !defined(FAKEFILE_DATASTRUCTURE_H)
#define FAKEFILE_DATASTRUCTURE_H

typedef struct Fakefile {
 	struct Fakefile *next;
	struct Fakefile *prev;
	struct Fakefile *head;
	struct Fakefile *tail;
	int type;
	char *command;
	
} Fakefile;





#endif
