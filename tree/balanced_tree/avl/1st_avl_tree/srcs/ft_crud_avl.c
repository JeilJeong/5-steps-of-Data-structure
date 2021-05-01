#include "../includes/ft_avl.h"

t_tree	*ft_create_node(int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree *)malloc(sizeof(t_tree))))
	{
		printf("malloc error: ft_create_node");
		ft_println(1);
		return (NULL);
	}
	ret->data = data;
	ret->height = 0;
	ret->left = NULL;
	ret->right = NULL;
	ret->parent = NULL;
	return (ret);
}

int		ft_insert_node(t_tree **root, t_tree *node)
{
	if (!node)
		return (0);
	if (!(*root))
	{
		*root = node;
		return (1);
	}
	else if ((*root)->data >= node->data)
		return (ft_insert_node(&((*root)->left), node));
	else if ((*root)->data < node->data)
		return (ft_insert_node(&((*root)->right), node));
	return (0);
}