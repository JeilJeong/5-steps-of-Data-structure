#include "../includes/ft_avl.h"

int		main(void)
{
	int		i;
	int		size;
	int		range;
	int		data;
	int		input;
	int		count;
	t_tree	*root;
	t_tree	*node;

	// initialization
	data = 0;
	count = 0;
	root = NULL;
	while (1)
	{
		input = 0;
		ft_println(1);
		printf("	---- MAIN MENU ----\n");
		printf("	[1] RANDOM  TEST\n");
		printf("	[2] EXIT PROGRAM\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
		{
			printf("	SIZE: ");
			scanf("%d", &size);
			printf("	RANGE: ");
			scanf("%d", &range);
			if (size < 0 || range < 0)
				continue;
			i = -1;
			srand((unsigned int)time(NULL));
			ft_println(1);
			while (++i < size)
			{
				data = rand() % range;
				printf("	[%d]: %d\n", i, data);
				while (!(node = ft_create_tree_node(data)))
					printf("	alloc error: ft_create_tree_node called by ft_main\n");
				count += ft_insert_tree_node(&root, &root, node, NULL, 0);
			}
			while (1)
			{
				input = 0;
				ft_println(1);
				printf("	---- SUB MENU ----\n");
				printf("	(1) PRINT  TREE MODE\n");
				printf("	(2) SEARCH NODE	MODE\n");
				printf("	(3) DELETE NODE MODE\n");
				printf("	(4) DELETE TREE	MODE\n");
				printf("	(5) RETURN TO   MAIN\n");
				printf("	>>> ");
				scanf("%d", &input);
				if (input == 1)
					ft_print_tree_mode(root, count);
				else if (input == 2)
					ft_search_node_mode(root);
				// else if (input == 3)
				// 	ft_delete_node_mode(&root, root);
				// else if (input == 4)
				// 	ft_delete_tree_mode(root);
				else if (input == 5)
					break;
			}
		}
		else if (input == 2)
		{
			ft_println(1);
			printf("	x-------------------x\n");
			printf("	| PROGRAM POWER OFF |\n");
			printf("	x-------------------x\n");
			return (NORMAL);
		}
	}

}