#include "../includes/ft_avl.h"

void	ft_search_node_mode(t_tree *root)
{
	int		input;

	if (!root)
		return ;
	while (1)
	{
		input = 0;
		ft_println(1);
		printf("	---- SEARCH MODE ----\n");
		printf("	[1] SEARCH   NODE\n");
		printf("	[2] RETURN TO SUB\n");
		printf("	>>> ");
		scanf("%d", &input);
		if (input == 1)
		{
			input = 0;
			ft_println(1);
			printf("	TYPE NODE : ");
			scanf("%d", &input);
			ft_println(1);
			ft_search_tree_node(root, input);
		}
		else if (input == 2)
			return ;
		ft_println(1);
	}
}

void	ft_search_tree_node(t_tree *root, int input)
{
	if (!root)
	{
		printf("	x-----------------------------------x\n");
		printf("	| --[%d] NODE DOESN'T EXIST IN TREE |\n", input);
		printf("	x-----------------------------------x\n");
		return ;
	}
	if (root->data > input)
		ft_search_tree_node(root->left, input);
	else if (root->data < input)
		ft_search_tree_node(root->right, input);
	else if (root->data == input)
	{
		if (root->parent)
		{
			printf("	++PARENT: %d, HEIGHT: %d\n", root->parent->data, root->parent->height);
			if (root->parent->left)
				printf("	+++LEFT: %d\n", root->parent->left->data);
			else
				printf("	+++LEFT: NONE\n");
			if (root->parent->right)
				printf("	+++RIGHT: %d\n", root->parent->right->data);
			else
				printf("	+++RIGHT: NONE\n");
		}
		else
			printf("	++PARENT: NONE\n");
		printf("	x----------------------x\n");
		printf("	| NODE: %d, HEIGHT: %d\n", root->data, root->height);
		printf("	x----------------------x\n");
		if (root->left)
			printf("	+LEFT_NODE: %d, HEIGHT: %d, PARENT: %d\n", root->left->data, root->left->height, root->left->parent->data);
		else
			printf("	+LEFT_NODE: NONE\n");
		if (root->right)
			printf("	+RIGHT_NODE: %d, HEIGHT: %d, PARENT: %d\n", root->right->data, root->right->height, root->right->parent->data);
		else
			printf("	+RIGHT_NODE: NODE\n");
		return ;
	}
}