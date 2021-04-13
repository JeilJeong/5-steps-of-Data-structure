#include "../includes/ft_list.h"

int		line_indent = 0;
int		count = 0;

int		main(void)
{
	int		data;
	t_list	*head;
	t_list	*node;
	int		pos;
	int		k;
	clock_t	start;
	clock_t end;

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

	// insert 100,000 nodes
	k = 0;
	srand((unsigned int)time(NULL));
	while (k < 100000)
	{
		data = rand() % 100000;
		if (!(node = ft_create_node(data)))
		{
			ft_main_error(__FILE__, __func__, __LINE__, "node alloc error");
			return (-1);
		}
		pos = rand() % 10;
		count += ft_insert_node(head, node, pos);
		k++;
	}

	// print node list
	ft_print_list(head);

	// bubble sort
	start = clock();
	ft_bubble_sort_list(head);
	end = clock();

	// print node list
	printf("\n*********************after sorting*********************\n");
	ft_print_list(head);
	
	// print sorting time
	printf("time = %.3f\n", (float)(end - start)/CLOCKS_PER_SEC);

	// delete certain node
	// pos = 1;
	// count -= ft_delete_node(head, pos);

	// // print node list
	// ft_print_list(head);
}
