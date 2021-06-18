#include "../includes/ft_avl.h"

int		main(void)
{
	int		data;
	int		input;
	int		size;
	int		range;
	int		i;
	int		count;
	t_tree	*root;
	t_tree	*node;

	data = 0;
	input = 0;
	size = 0;
	range = 0;
	count = 0;
	root = NULL;
	node = NULL;
	while (1)
	{
		ft_println(1);
		printf("+++[Main Menu]+++\n");
		printf("[1] Ramdom Input\n");
		printf("[2] Manual Input\n");
		printf("[3] Exit Program\n");
		printf(">>> ");
		scanf("%d", &input);
		if (input == 1 || input == 2)
		{
			ft_println(1);
			printf("Size: ");
			scanf("%d", &size);
			if (input == 1)
			{
				printf("Range: ");
				scanf("%d", &range);
			}
			i = -1;
			srand(time(NULL));
			while (++i < size)
			{
				if (input == 1)
				{
					data = rand() % range;
					printf("[%d] %d\n", i, data);
				}
				else if (input == 2)
				{
					printf ("[%d] ", i);
					scanf("%d", &data);
				}
				node = ft_create_tree_node(data);
				ft_insert_tree_node(&root, root, node, NULL, &count);
			}
			ft_println(1);
			while (1)
			{
				printf("+++[Tree Menu]+++\n");
				printf("{1} Search    Node\n");
				printf("{2} Traversal Node\n");
				printf("{3} Delete    Node\n");
				printf("{4} Delete    Tree\n");
				printf("{5} Return to Main\n");
				printf(">>> ");
				scanf("%d", &input);
				if (input == 1)
					ft_search_tree_mode(root, node);
				else if (input == 2)
					ft_traversal_tree_mode(root);
				else if (input == 3)
					ft_delete_tree_node(&root, node, &count);
				else if (input == 4)
					ft_delete_tree(root);
				else if (input == 5)
				{
					ft_delete_tree(root);
					break;
				}
			}
		}
		if (input == 3)
			break;
	}
}