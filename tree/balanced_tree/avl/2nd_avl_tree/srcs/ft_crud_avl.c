#include "../includes/ft_avl.h"

t_tree	*ft_create_node(int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree *)malloc(sizeof(t_tree))))
	{
		printf("malloc_error: ft_create_node\n");
		return (NULL);
	}
	ret->data = data;
	ret->height = 0;
	ret->left = NULL;
	ret->right = NULL;
	ret->parent = NULL;
	return (ret);
}

t_tree	*ft_insert_node(t_tree **root, t_tree *node, int height, t_tree *parent)
{
	if (!node)
		return (NULL);
	if (!(*root))
	{
		node->height = height;
		node->parent = parent;
		*root = node;
		return (*root);
	}
	if ((*root)->data >= node->data)
		(*root)->left = ft_insert_node(&((*root)->left), node, height + 1, *root);
	else if ((*root)->data < node->data)
		(*root)->right = ft_insert_node(&((*root)->right), node, height + 1, *root);
	return (*root);
}

t_tree	*ft_search_node(t_tree *root)
{
	printf("")
}