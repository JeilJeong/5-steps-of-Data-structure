#ifndef TEST
# define TEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct Linked_List_Node_Type{
	int				data;
	struct Linked_List_Node_Type	*next;
} List_Node;
typedef struct Linked_List_Type{
	int		node_count;
	List_Node	header;
} List;

# define TRUE	1
# define FALSE	0

#endif
