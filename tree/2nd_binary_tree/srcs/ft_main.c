#include "../includes/ft_tree.h"

int		count = 0;

int		main()
{
	int		i;
	int		data;
	int		input;
	t_tree	*root;

	i = 0;
	root = NULL;
	input = 0;
	srand((unsigned int)time(NULL));
	while (i < 10)
	{
		data = rand() % 100;
		printf("[%d] ", data);
		count += ft_insert_node(&root, data);
		i++;
	}
	printf("\n");
	printf("**************************************** < total node = %d > ****************************************\n\n", count);
	// printf("PRE_ORDER: ");
	// ft_print_node(root, PRE_ORDER);
	// printf("\n");
	printf("IN_ORDER: ");
	ft_print_node(root, IN_ORDER);
	printf("\n");
	// printf("POST_ORDER: ");
	// ft_print_node(root, POST_ORDER);
	// printf("\n");

	while (1)
	{
		printf("\ntype the search number[negative num = exit]: ");
		scanf("%d", &input);
		if (input < 0)
			break;
		ft_search_node(root, input);
	}

	while (1)
	{
		printf("\ntype the delete number[negative num = exit]: ");
		scanf("%d", &input);
		if (input < 0)
			break;
		root = ft_delete_node(root, input);
		printf("IN_ORDER: ");
		ft_print_node(root, IN_ORDER);
		printf("\n");
		printf("< left node = %d >\n", count);
		if (root == NULL)
		{
			printf("tree is deleted completely\n");
			break;
		}
	}
}