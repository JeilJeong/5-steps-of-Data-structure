#include "../includes/ft_tree.h"

void	ft_print_tree(t_tree *root, int order)
{
	if (root == NULL)
		return ;
	else if (order == PRE_ORDER)
	{
		printf("%d ", root->data);
		ft_print_tree(root->left, order);
		ft_print_tree(root->right, order);
	}
	else if (order == IN_ORDER)
	{
		ft_print_tree(root->left, order);
		printf("%d ", root->data);
		ft_print_tree(root->right, order);
	}
	else if (order == POST_ORDER)
	{
		ft_print_tree(root->left, order);
		ft_print_tree(root->right, order);
		printf("%d ", root->data);
	}
}

void	ft_println(int times)
{
	while (times)
	{
		printf("\n");
		times--;
	}
}

void	ft_print_input(int data)
{
	printf("%d ", data);
}

void	ft_print_count(int count)
{
	printf("	< left node: %d >\n", count);
}

void	ft_print_delete_case(int input)
{
	if (input == DEL_TERMINAL)
		printf("	Delete node: Node is Terminal");
	else if (input == DEL_BOTH)
		printf("	Delte node: Node have both left and right sub-tree");
	else if (input == DEL_LEFT)
		printf("	Delte node: Node has left sub-tree");
	else if (input == DEL_RIGHT)
		printf("	Delte node: Node has right sub-tree");
	ft_println(1);
}