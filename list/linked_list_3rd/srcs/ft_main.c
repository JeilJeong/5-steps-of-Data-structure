
#include "../includes/ft_list.h"

int		main(void)
{
	int		data;
	t_list	*head;
	t_list	*node;
	int		pos;

	data = 0;

	// creates a list head
	if (!(head = ft_init()))
	{
		ft_main_error(__FILE__, __func__, __LINE__, "head alloc error");
		return (-1);
	}

	// create list nodes
	if (!(node = ft_create_node(data)))
	{
		ft_main_error(__FILE__, __func__, __LINE__, "node alloc error");
		return (-1);
	}
	// insert list node
	pos = 0;
	count += ft_insert_node(head, node, pos);

	data = 1;
	// create list nodes
	if (!(node = ft_create_node(data)))
	{
		ft_main_error(__FILE__, __func__, __LINE__, "node alloc error");
		return (-1);
	}
	// insert list node
	pos = 0;
	count += ft_insert_node(head, node, pos);

	data = 2;
	// create list nodes
	if (!(node = ft_create_node(data)))
	{
		ft_main_error(__FILE__, __func__, __LINE__, "node alloc error");
		return (-1);
	}
	// insert list node
	pos = 0;
	count += ft_insert_node(head, node, pos);

	t_list	*tmp;

	tmp = head->next;
	while (tmp)
	{
		printf("[%d]", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");

	// print node list
	ft_print_list(head);

	// sorting list
	ft_bubble_sort_list(head);

	// print node list
	ft_print_list(head);
	
	// delete certain node
	pos = 1;
	count -= ft_delete_node(head, pos);

	// print node list
	ft_print_list(head);
}