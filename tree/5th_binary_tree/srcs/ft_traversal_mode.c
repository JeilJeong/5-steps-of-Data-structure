#include "../includes/ft_avl.h"

void	ft_traversal_node_mode(t_tree *root)
{
	int		input;

	if (!root)
		return ;
	while (1)
	{
		input = 0;
		ft_println(1);
		printf("	-------[Traversal Menu]------\n");
		printf("	(1) Pre    Order\n");
		printf("	(2) In     Order\n");
		printf("	(3) Post   Order\n");
		printf("	(4) Level Traver\n");
		printf("	(5) Back to Menu\n");
		printf("	>>> ");
		scanf("%d", &input);
		if (input == 1 || input == 2 || input == 3)
		{
			if (input == 1)
				printf("	Pre-order: ");
			else if (input == 2)
				printf("	In-order: ");
			else if (input == 3)
				printf("	Post-order: ");
			ft_traversal_order(root, input);
			ft_println(1);
		}
		else if (input == 4)
			ft_traversal_level_mode(root);
		else if (input == 5)
			return ;
	}
}

void	ft_traversal_order(t_tree *root, int order)
{
	if (!root)
		return ;
	if (order == 1)
	{
		printf("%d ", root->data);
		ft_traversal_order(root->left, order);
		ft_traversal_order(root->right, order);
	}
	else if (order == 2)
	{
		ft_traversal_order(root->left, order);
		printf("%d ", root->data);
		ft_traversal_order(root->right, order);
	}
	else if (order == 3)
	{
		ft_traversal_order(root->left, order);
		ft_traversal_order(root->right, order);
		printf("%d ", root->data);
	}
}