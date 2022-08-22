typedef struct node {
 	struct node *next;
	struct node *parent;
	struct node *children;
	struct node *prev;
	int timestamp;
	char *name;
	int type;
} Node;

 /* 
 This struct holds imprtant information about a
doubly-linked Prio_que such as the head and tail
nodes and the size of the list.
*/
typedef struct {

	Node *root;
	Node *current_dir ;
	
 }Ournix;
 