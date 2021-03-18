#ifndef LINKED_LIST
# define LINKEKD_LIST

typedef struct LinkedListNodeType{
	int				data;
	struct LinkedListNodeType	*next;
} List_Node;

typedef struct LikedListType{
	int		node_num;
	List_Node	header;
} L_List;

L_List		*create_list(void);
int		add_node(L_List *list, const int p, List_Node *e);
int		remove_node(L_List *list, const int p);
void		delete_list(L_List *list);
List_Node	*get_node(L_List *list, const int p);
void		print_node(L_List *list);

#define TRUE	1
#define FALSE	0

#endif
