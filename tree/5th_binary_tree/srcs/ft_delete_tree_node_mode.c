#include "../includes/ft_avl.h"

void	ft_delete_node_mode(t_tree **og_root, t_tree *root, t_tree *parent, int *count)
{
	int		data;

	data = 0;
	printf("	Data: ");
	scanf("%d", &data);
	ft_delete_tree_node(og_root, root, parent, count, data);
	ft_traversal_level_mode(*og_root);
	printf("	Count: %d\n", *count);
}

t_tree	*ft_delete_tree_node(t_tree **og_root, t_tree *root, t_tree *parent, int *count, int data)
{
	t_tree *ret;
	t_tree *max_node;

	ret = NULL;
	max_node = NULL;
	if (!root)
		return (NULL);
	if (root->data > data)
		root->left = ft_delete_tree_node(og_root, root->left, root, count, data);
	else if (root->data < data)
		root->right = ft_delete_tree_node(og_root, root->right, root, count, data);
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			*count -= 1;
			if (!parent)
				*og_root = ret;
			free(root);
			return (ret);
		}
		else if (!root->left && root->right)
		{
			ret = root->right;
			ret->parent = root->parent;
			if (!parent)
				*og_root = ret;
			*count -= 1;
			free(root);
			return (ret);
		}
		else if (root->left && !root->right)
		{
			ret = root->left;
			ret->parent = root->parent;
			if (!parent)
				*og_root = ret;
			*count -= 1;
			free(root);
			return (ret);
		}
		if (!(max_node = ft_find_max_node_in_left(root->left)))
		{
			printf("	function error: ft_find_max_node_in_left << ft_delete_tree_node\n");
			return (ret);
		}
		root->data = max_node->data;
		root->left = ft_delete_tree_node(og_root, root->left, root, count, max_node->data);
		return (root);
	}
	return (root);
}

t_tree *ft_find_max_node_in_left(t_tree *root)
{
	if(!root)
		return (NULL);
	if (root->right)
		return (ft_find_max_node_in_left(root->right));
	return (root);
}