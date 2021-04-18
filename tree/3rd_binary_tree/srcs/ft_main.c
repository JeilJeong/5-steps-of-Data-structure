#include "../includes/ft_tree.h"

int		main(void)
{
	int		i;
	int		data;
	int		count;
	int		input;
	t_tree	*root;
	t_tree	*node;

	i = -1;
	count = 0;
	input = 0;
	root = NULL;
	node = NULL;
	srand((unsigned int)time(NULL));
	ft_println(1);
	printf("	input num: ");
	while (++i < 10)
	{
		data = rand() % 100;
		ft_print_input(data);
		while (!node)
			node = ft_create_node(data);
		count += ft_insert_node(&root, node);
		node = NULL;
	}
	ft_println(2);
	while (1)
	{
		printf("	Type the number:\n");
		printf("	[1] Print	Tree\n");
		printf("	[2] Search	Node\n");
		printf("	[3] Level	Traversal\n");
		printf("	[4] Delete	Node\n");
		printf("	[5] Delete	Tree\n");
		printf("	[6] Count	Node\n");
		printf("	[7] Exit\n");
		ft_println(1);
		printf("	select number: ");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("	Tree: ");
			ft_print_tree(root, IN_ORDER);
			ft_println(1);
		}
		else if (input == 2)
			ft_search_node(root);
		else if (input == 3)
			ft_level_traversal(root);
		else if (input == 4)
			root = ft_delete_node(root, &count);
		else if (input == 5)
			root = ft_delete_tree(root);
		else if (input == 6)
			ft_print_count(count);
		else if (input == 7)
			break;
		ft_println(1);
	}
}