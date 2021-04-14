#include "../includes/ft_tree.h"

t_tree	*ft_create_node(int data)
{
	t_tree	*node;

	if (!(node = (t_tree *)malloc(sizeof(node))))
	{
		printf("malloc error: ft_insert_node");
		return (NULL);
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int		ft_insert_node(t_tree **root, t_tree *node)
{
	if (*root == NULL)
	{
		*root = node;
		return (1);
	}
	else if ((*root)->data > node->data)
		return (ft_insert_node(&((*root)->left), node));
	else if ((*root)->data < node->data)
		return (ft_insert_node(&((*root)->right), node));
	return (0);
}

void	ft_print_tree(t_tree *root, int order)
{
	if (root == NULL)
		return ;
	if (order == PRE_ORDER)
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