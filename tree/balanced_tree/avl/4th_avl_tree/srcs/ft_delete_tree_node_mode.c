#include "../includes/ft_avl.h"

void	ft_delete_node_mode(t_tree **og_root, t_tree *root, t_tree *parent, int *count)
{
	int			data;
	t_retTree	*node;

	data = 0;
	printf("	Data: ");
	scanf("%d", &data);
	if ((node = ft_delete_tree_node(og_root, root, parent, count, data)))
		ft_rebalancing_tree(og_root, node->rebal_node);
	ft_traversal_level_mode(*og_root);
	free(node);
	node = NULL;
	printf("	Count: %d\n", *count);
}

t_retTree	*ft_delete_tree_node(t_tree **og_root, t_tree *root, t_tree *parent, int *count, int data)
{
	t_tree		*ret;
	t_tree		*max_node;
	t_retTree	*node;

	ret = NULL;
	max_node = NULL;
	node = NULL;
	if (!root)
		return (NULL);
	if (root->data > data)
	{
		if ((node = ft_delete_tree_node(og_root, root->left, root, count, data)))
		{
			root->left = node->child;
			node->child = root;
		}
	}
	else if (root->data < data)
	{
		if ((node = ft_delete_tree_node(og_root, root->right, root, count, data)))
		{
			root->right = node->child;
			node->child = root;
		}
	}
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			*count -= 1;
			if (!parent)
				*og_root = ret;
			node = ft_create_retTree(ret, root->parent);
			free(root);
			return (node);
		}
		else if (!root->left && root->right)
		{
			ret = root->right;
			ret->parent = root->parent;
			if (!parent)
				*og_root = ret;
			*count -= 1;
			node = ft_create_retTree(ret, root->parent);
			free(root);
			return (node);
		}
		else if (root->left && !root->right)
		{
			ret = root->left;
			ret->parent = root->parent;
			if (!parent)
				*og_root = ret;
			*count -= 1;
			node = ft_create_retTree(ret, root->parent);
			free(root);
			return (node);
		}
		if (!(max_node = ft_find_max_node_in_left(root->left)))
		{
			printf("	function error: ft_find_max_node_in_left << ft_delete_tree_node\n");
			return (node);
		}
		root->data = max_node->data;
		if ((node = ft_delete_tree_node(og_root, root->left, root, count, max_node->data)))
		{
			root->left = node->child;
			node->child = root;
		}
		return (node);
	}
	return (node);
}

t_tree *ft_find_max_node_in_left(t_tree *root)
{
	if(!root)
		return (NULL);
	if (root->right)
		return (ft_find_max_node_in_left(root->right));
	return (root);
}

t_retTree	*ft_create_retTree(t_tree *child, t_tree *rebal_node)
{
	t_retTree	*ret;

	while (!(ret = (t_retTree *)malloc(sizeof(t_retTree))))
		printf("	malloc error: ft_create_retTree\n");
	ret->child = child;
	ret->rebal_node = rebal_node;
	return (ret);
}