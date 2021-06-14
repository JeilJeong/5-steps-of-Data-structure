#include "../includes/ft_avl.h"

t_tree	*ft_create_tree_node(int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree *)malloc(sizeof(t_tree))))
	{
		printf("	malloc error: ft_create_tree_node\n");
		return (NULL);
	}
	ret->data = data;
	ret->left = NULL;
	ret->right = NULL;
	ret->parent = NULL;
	return (ret);
}

void	ft_insert_tree_node(t_tree **root, t_tree *node, t_tree *parent, int *count)
{
	if (!node)
		return ;
	if (!(*root))
	{
		node->parent = parent;
		*root = node;
		*count += 1;
		return ;
	}
	if ((*root)->data > node->data)
		ft_insert_tree_node(&((*root)->left), node, *root, count);
	else if ((*root)->data < node->data)
		ft_insert_tree_node(&((*root)->right), node, *root, count);
	else if ((*root)->data == node->data)
		free(node);
}

t_tree	*ft_remove_tree_mode(t_tree **og_root, t_tree *root, int *count)
{
	t_tree *ret;

	ret = ft_remove_tree(root, count);
	*og_root = ret;
	printf("	Count: %d\n", *count);
	return (ret);
}

t_tree *ft_remove_tree(t_tree *root, int *count)
{
	if (!root)
		return (NULL);
	if (root->left)
		root->left = ft_remove_tree(root->left, count);
	if (root->right)
		root->right = ft_remove_tree(root->right, count);
	if (!root->left && !root->right)
	{
		*count -= 1;
		free(root);
	}
	return (NULL);	
}