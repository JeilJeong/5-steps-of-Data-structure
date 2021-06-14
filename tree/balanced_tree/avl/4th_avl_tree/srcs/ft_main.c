#include "../includes/ft_avl.h"

int		main(void)
{
	int 	data;
	int		input;
	int		count;
	int		size;
	int		range;
	int		i;
	t_tree	*root;
	t_tree	*node;

	// initialization
	data = 0;
	input = 0;
	count = 0;
	size = 0;
	range = 0;
	root = NULL;
	node = NULL;
	
	// ft_create_tree_node;
	while(1)
	{	
		ft_println(1);
		printf("	---------[Main Menu]---------\n");
		printf("	[1] Random Data\n");
		printf("	[2] Input  Data\n");
		printf("	[3] Exit\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1 || input == 2)
		{
			// ft_create_tree_node & ft_insert_tree_node
			i = -1;
			printf("	SIZE: ");
			scanf("%d", &size);
			if (input == 1)
		 	{
				printf("	RANGE: ");
				scanf("%d", &range);
				srand(time(NULL));
			 } 
			while (++i < size)
			{
				if (input == 1)
				{
					data = rand() % range;
					printf("	[%d] %d\n", i, data);
				}
				else
				{
					printf("	[%d] ", i);
					scanf("%d", &data);
				}
				while (!(node = ft_create_tree_node(data)))
					printf("	alloc error: ft_main called by ft_create_tree_node\n");
				ft_insert_tree_node(&root, node, NULL, &count);
			}
			while (1)
			{
				ft_println(1);
				printf("	---------[Tree Menu]---------\n");
				printf("	{1} Search    Node\n");
				printf("	{2} Traversal Node\n");
				printf("	{3} Delete    Node\n");
				printf("	{4} Remove    Tree\n");
				printf("	{5} Return to Menu\n");
				printf("	>>> ");
				scanf("%d", &input);
				if (input == 1)
					ft_search_node_mode(root);
				else if (input == 2)
					ft_traversal_node_mode(root);
				else if (input == 3)
					ft_delete_node_mode(&root, root, NULL, &count);
				else if (input == 4)
					ft_remove_tree_mode(&root, root, &count);
				else if (input == 5)
				{
					ft_remove_tree_mode(&root, root, &count);
					break;
				}
			}
		}
		else if (input == 3)
			return (NORMAL);
	}
}