#include "linked_list_2nd.h"

List		*create_list(void)
{
	List	*pReturn;

	pReturn = NULL;
	if ((pReturn = (List *)malloc(sizeof(List))) == NULL)
	{
		perror("[create list] malloc error");
		return (pReturn);
	}
	memset(pReturn, 0, sizeof(pReturn));
	return (pReturn);
}

List_Node	*create_node(int d)
{
	List_Node	*pReturn;

	pReturn = NULL;
	if ((pReturn = (List_Node *)malloc(sizeof(List_Node))) == NULL)
	{
		perror("[create node] malloc error");
		return (pReturn);
	}
	pReturn->data = d;
	pReturn->next = NULL;
	return (pReturn);
}

int		add_node(List *list, int p, List_Node *n)
{
	List_Node	*prev;
	int		i;

	prev = NULL;
	i = 0;
	if (list == NULL)
	{
		perror("[add_node] list argument is NULL");
		return (FALSE);
	}
	if (p < 0 || p > list->node_count)
	{
		perror("[add_node] position argument is invalid");
		return (FALSE);
	}
	if (n == NULL)
	{
		perror("[add_node] Node argument is NULL");
		return (FALSE);
	}
	prev = &(list->header);
	while (i < p)
	{
		prev = prev->next;
		i++;
	}
	n->next = prev->next;
	prev->next = n;
	list->node_count++;
	return (TRUE);	
}

int		remove_node(List *list, int p)
{
	List_Node	*prev;
	List_Node	*target;
	int		i;

	prev = NULL;
	target = NULL;
	i = 0;
	if (list == NULL)
	{
		perror("[remove_node] list argument is NULL");
		return (FALSE);
	}
	if (p < 0 || p >= list->node_count)
	{
		perror("[remove_node] position argument is invalid");
		return (FALSE);
	}
	prev = &(list->header);
	while (i < p)
	{
		prev = prev->next;
		i++;
	}
	target = prev->next;
	prev->next = target->next;
	free(target);
	list->node_count--;
	return (TRUE);
}

List_Node	*get_node(List *list, int p)
{
	List_Node	*pReturn;
	int	i;

	pReturn = NULL;
	i = 0;
	if (list == NULL)
	{
		perror("[get_node] list argument is NULL");
		return (pReturn);
	}
	if (p < 0 || p >= list->node_count)
	{
		perror("[get_node] position argument is invalid");
		return (pReturn);
	}
	pReturn = &(list->header);
	while (i <= p)
	{
		pReturn = pReturn->next;
		i++;
	}
	return (pReturn);
}

void		delete_list(List *list)
{
	List_Node *prev;
	List_Node *present;

	prev = NULL;
	present = NULL;
	if (list != NULL)
	{
		prev = list->header.next;
		while (prev->next != NULL)
		{
			present = prev->next;
			free(prev);
			prev = present;
		}
		free(prev);
		free(list);
	}
}

void		display_list(List *list)
{
	List_Node	*present;
	int		i;

	present = NULL;
	i = 0;
	if (list != NULL)
	{
		present = list->header.next;
		while (present->next != NULL)
		{
			printf("pNode[%5d] : %5d\n", i, present->data);
			i++;
			present = present->next;
		}
		printf("pNode[%5d] : %5d\n\n", i, present->data);
		printf("Current Node Count = %d\n\n", list->node_count);
	}
}

int	main(void)
{
	List		*list;
	List_Node	*node;
	int		i;

	list = NULL;
	node = NULL;
	if ((list = create_list()) == NULL)
	{
		perror("[main] create_list error");
		return (-1);
	}
	i = 0;
	srand((unsigned int)time(NULL));
	while (i < 10)
	{
		if ((node = create_node((int)rand() % 100)) == NULL)
		{
			perror("[main] create_node error");
			return (-1);
		}
		if (add_node(list, i, node) == 0)
		{
			perror("[main] add_node error");
			return (-1);
		}
		i++;
	}
	display_list(list);
	i = 0;
	while (i < 5)
	{
		remove_node(list, (int)rand() % 10);
		i++;
	}
	display_list(list);
	delete_list(list);
}
