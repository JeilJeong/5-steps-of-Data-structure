#include "../includes/ft_avl.h"

void	ft_delete_node(t_tree **og_root, t_tree *root, int *count)
{
	int		input;

	input = 0;
	while (1)
	{
		printf("	*** DELETE NODE MODE ***\n");
		printf("	[1] TYPE NODE\n");
		printf("	[2] BACK TO MAIN\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
		{
			printf("	Type data: ");
			scanf("%d", &input);
			ft_delete_tree_node(og_root, root, root->parent, input, count);
			ft_println(1);
		}
		else if (input == 2)
			return ;
	}
}

void	ft_delete_tree_node(t_tree **og_root, t_tree *root, t_tree *parent, int data, int *count)
{
	t_tree	*max_node;
	t_tree	*ret;

	ret = NULL;
	if (!root)
		return ;
	if (root->data > data)
		ft_delete_tree_node(og_root, root->left, root, data, count);
	else if (root->data < data)
		ft_delete_tree_node(og_root, root->right, root, data, count);
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			printf("	[%d]: leaf node\n", root->data);
			ret = root->parent;
			if (root->height == 0)
				*og_root = NULL;
			else
			{
				if (parent->left == root)
					parent->left = NULL;
				else if (parent->right == root)
					parent->right = NULL;
			}
			free(root);
			*count -= 1;
			if (ret)
				ft_balance_check_deletion_mode(og_root, ret);
			return ;
		}
		else if (root->left && !root->right)
		{
			printf("	[%d]: has left sub tree\n", root->data);
			ret = root->left;
			if (root->height == 0)
				*og_root = ret;
			else
			{
				if (parent->left == root)
					parent->left = ret;
				else if (parent->right == root)
					parent->right = ret;
			}
			free(root);
			*count -= 1;
			ret->parent = parent;
			ft_resolve_height(ret, ret->height - 1);
			ft_balance_check_deletion_mode(og_root, ret);
			return ;
		}
		else if (!root->left && root->right)
		{
			printf("	[%d]: has right sub tree\n", root->data);
			ret = root->right;
			if (root->height == 0)
				*og_root = ret;
			else
			{
				if (parent->left == root)
					parent->left = ret;
				else if (parent->right == root)
					parent->right = ret;
			}
			free(root);
			*count -= 1;
			ret->parent = parent;
			ft_resolve_height(ret, ret->height - 1);
			ft_balance_check_deletion_mode(og_root, ret);
			return ;
		}
		printf("	[%d]: has both left and right sub tree\n", root->data);
		max_node = ft_find_left_max(root->left);
		root->data = max_node->data;
		ft_delete_tree_node(og_root, root->left, root, max_node->data, count);
	}
}

void	ft_resolve_height(t_tree *root, int height)
{
	if (!root)
		return ;
	root->height = height;
	if (root->left)
		ft_resolve_height(root->left, height - 1);
	if (root->right)
		ft_resolve_height(root->right, height - 1);
}

t_tree	*ft_find_left_max(t_tree *root)
{
	if (!root)
		return (NULL);
	if (root->right)
		return (ft_find_left_max(root->right));
	return (root);
}