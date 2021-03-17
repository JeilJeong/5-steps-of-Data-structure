#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "linked_list.h"

L_List	*create_list(void)
{
	L_List	*pReturn;

	pReturn = NULL;
	if ((pReturn = (L_List *)malloc(sizeof(L_List))) == NULL)
	{
		perror("create_list malloc is failed");
		return (pReturn);
	}
	memset(pReturn, 0, sizeof(L_List));
	return (pReturn);
}

int	add_node(L_List *list, const int p, List_Node e)
{
	List_Node	*prev;
	int		i;
	
	if (list == NULL)
	{
		perror("list argument of add_node function is NULL");
		return (FALSE);
	}
	if (p < 0 || p > list->node_num)
	{
		perror("position argument of add_node function is not valid");
		return (FALSE);
	}
	prev = &(list->header);
	i = 0;
	while (i < p)
	{
		prev = prev->next;
		i++;
	}
	e.next = prev->next;
	prev->next = &(e);
	list->node_num++;
	return (TRUE);
}

int	remove_node(L_List *list, const int p)
{
	List_Node	*prev;
	List_Node	*target;
	int		i;
	
	if (list == NULL)
	{
		perror("list argument of remove_node function is NULL");
		return (FALSE);
	}
	if (p < 0 || p >= list->node_num)
	{
		perror("position argument of remove_node function is not valid");
		return (FALSE);
	}
	prev = &(list->header);
	i = 0;
	while (i < p)
	{
		prev = prev->next;
		i++;
	}

	target = prev->next;
	printf("%d\n", list);
	printf("%d\n", prev->next);
	write(1, "**\n", 3);
	prev->next = target->next;
	write(1, "||\n", 3);
	free(target);
	write(1, "^^\n", 3);
	list->node_num--;
	write(1, "^^\n", 3);
	return (TRUE);
}

void	delete_list(L_List *list)
{
	List_Node	*prev;
	List_Node	*tmp;

	if (list != NULL)
	{
		prev = list->header.next;
		while (prev->next != NULL)
		{
			tmp = prev->next;
			free(prev);
			prev = tmp;
		}
		free(tmp);
		free(list);
	}
}

List_Node	*get_node(L_List *list, const int p)
{
	List_Node	*pReturn;
	List_Node	*pNode;
	int		i;

	pReturn = NULL;
	if (list == NULL)
	{
		perror("list argument of get_node function is NULL");
		return (pReturn);
	}
	if (p < 0 || p > list->node_num)
	{
		perror("position argument of get_node function is not valid");
		return (pReturn);
	}
	pNode = &(list->header);
	i = 0;
	while (i <= p)
	{
		pNode = pNode->next;
		i++;
	}
	pReturn = pNode;
	return (pReturn);
}

void	print_node(L_List *list)
{
	if (list == NULL)
	{
		perror("list argument of print_node function is NULL");
		return ;
	}
}

int	main(void)
{
	L_List		*list;
	List_Node	tmp1;
	List_Node	tmp2;
	List_Node	tmp3;
	List_Node	*test;

	if ((list = create_list()) == NULL)
	{
		perror("create list error");
		return (-1);
	}
	tmp1.data = 1;
	tmp1.next = NULL;
	tmp2.data = 2;
	tmp2.next = NULL;
	tmp3.data = 3;
	tmp3.next = NULL;
	add_node(list, 2, tmp1);
	add_node(list, 0, tmp1);
	add_node(list, 2, tmp2);
	add_node(list, 1, tmp2);
	add_node(list, 1, tmp3);
	test = get_node(list, 1);
	printf("%d\n", test->data);
	write(1, "??\n", 3);
	remove_node(list, 1);
	write(1, "!!\n", 3);
	test = get_node(list, 1);
	printf("%d\n", test->data);
	delete_list(list);
	return (0);
}
