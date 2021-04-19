#include "../includes/ft_tree.h"

int		main(void)
{
	int		i;
	int		size;
	int		range;
	int		data;
	int		count;
	int		input;
	t_tree	*root;
	t_tree	*tree_node;

	while (1)
	{
		i = -1;
		size = 0;
		range = 0;
		data = 0;
		count = 0;
		input = 0;
		root = NULL;
		ft_println(2);
		printf("	Tree Size: ");
		scanf("%d", &size);
		printf("	Number Range(from 1 to ?): ");
		scanf("%d", &range);
		srand((unsigned int)time(NULL));
		printf("	Input Number : ");
		while (++i < size)
		{
			data = rand() % range + 1;
			printf("%d ", data);
			tree_node = ft_create_tree_node(data);
			ft_insert_tree_node(&root, tree_node, &count);
		}
		ft_println(2);
		while (1)
		{
			printf("	[1] Print	Tree\n");
			printf("	[2] Level	Trav\n");
			printf("	[3] Search	Node\n");
			printf("	[4] Delete	Node\n");
			printf("	[5] Delete	Tree\n");
			printf("	[6] Count	Node\n");
			printf("	[7] Retry	Tree\n");
			printf("	[8] Exit	Prog\n");
			ft_println(1);
			printf("	Type Number: ");
			scanf("%d", &input);
			ft_println(1);
			if (input == 1)
			{
				printf("	Inorder Traversal: ");
				ft_print_tree(root);
				ft_println(2);
			}
			else if (input == 2)
			{
				printf("	Level Traversal: ");
				ft_level_traversal(root);
				ft_println(2);
			}
			else if (input == 3)
			{
				printf("	Type node(to find): ");
				scanf("%d", &input);
				ft_println(1);
				printf("	Search Node: ");
				ft_search_tree_node(root, input, 1);
				ft_println(2);
			}
			else if (input == 4)
			{
				printf("	Type node(to remove): ");
				scanf("%d", &input);
				ft_println(1);
				printf ("	Delete Case: ");
				root = ft_delete_tree_node(root, input, &count);
				ft_println(2);
			}
			else if (input == 5)
			{
				root = ft_delete_tree(root, &count);
				if (!root)
					printf("	Tree has been removed\n\n");
			}
			else if (input == 6)
				printf("	< Count Node: %d >\n\n", count);
			else if (input == 7)
				break;
			else if (input == 8)
				return (0);
		}
	}
}