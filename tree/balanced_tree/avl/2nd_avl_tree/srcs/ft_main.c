#include "../includes/ft_avl.h"

int		main(void)
{
	int		i;
	int		data;
	int		input;
	int		size;
	int		range;
	int		count;
	t_tree	*root;
	t_tree	*node;
	int		arr[2] = {82, 94};
	// int		arr[10] = {32, 7, 88, 82, 94};
	// {66, 18, 88, 7, 38, 82, 94, 0, 32, 38};

	// ft_create_node & insert node
	count = 0;
	input = 0;
	root = NULL;
	printf("	Tree Size: ");
	scanf("%d", &size);
	printf("	Tree Range: ");
	scanf("%d", &range);
	i = -1;
	ft_println(1);
	printf("	[1] MANUAL INPUT\n");
	printf("	[2] RANDOM INPUT\n");
	printf("	[3] TEST   INPUT\n");
	printf("	>>> ");
	scanf("%d", &input);
	ft_println(1);
	if (input == 1)
	{
		while (++i < size)
		{
			printf("	[%d] : ", i);
			scanf("%d", &data);
			if (!(node = ft_create_node(data)))
			{
				printf("alloc error: ft_main\n");
				return (ABNORMAL);
			}
			if ((ft_insert_node(&root, &root, node, 0, NULL)))
				count += 1;
		}
	}
	else if (input == 2)
	{
		srand((unsigned int)time(NULL));
		while (++i < size)
		{
			data = rand() % range;
			printf("	[%d] Data: %d\n", i, data);
			if (!(node = ft_create_node(data)))
			{
				printf("alloc error: ft_main\n");
				return (ABNORMAL);
			}
			if ((ft_insert_node(&root, &root, node, 0, NULL)))
				count += 1;
		}
	}
	else if (input == 3)
	{
		while (++i < size)
		{
			printf("	[%d] : %d\n", i, arr[i]);
			data = arr[i];
			if (!(node = ft_create_node(data)))
			{
				printf("alloc error: ft_main\n");
				return (ABNORMAL);
			}
			if ((ft_insert_node(&root, &root, node, 0, NULL)))
				count += 1;
		}
	}
	ft_println(1);
	while (1)
	{
		input = 0;
		printf("	***** MAIN *****\n");
		printf("	[1] PRINT	TREE\n");
		printf("	[2] SEARCH	NODE\n");
		printf("	[3] DELETE	NODE\n");
		printf("	[4] DELETE	TREE\n");
		printf("	[5] EXIT	PROGRAM\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
			ft_print_tree(root, count);
		else if (input == 2)
			ft_search_node(root);
		else if (input == 3)
			ft_delete_node(&root, root, &count);
		else if (input == 4)
		{
			root = ft_delete_tree(root);
			if (!root)
			{
				count = 0;
				printf("	>>> Tree has been deleted completely\n");
				ft_println(1);
			}
		}
		else if (input == 5)
			return (NORMAL);
	}
}