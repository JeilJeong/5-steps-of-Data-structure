#include "../includes/ft_avl.h"

void	ft_balancing_tree(t_tree **og_root, t_tree *node)
{
	t_tree	*x;
	t_tree	*y;
	t_tree	*z;
	t_tree	*ret_node;
	int		height_diff;

	x = NULL;
	y = NULL;
	z = NULL;
	ret_node = NULL;
	height_diff = 0;
	if (!node)
		return ;
	x = node;
	if (x->parent)
	{
		y = x->parent;
		if (x->parent->parent)
			z = x->parent->parent;
	}
	while (x && y && z)
	{
		height_diff = ft_compare_height (z);
		if (height_diff > 1)
		{
			if (ft_compare_height(y) > 0)
				ret_node = ft_rotate_ll(x);
			else
				ret_node = ft_rotate_lr(x);
			if (ret_node)
			{
				if (ret_node->parent == NULL)
					*og_root = ret_node;
				x = ret_node;
				y = x->parent;
				if (x->parent)
					z = x->parent->parent;
				continue;
			}
		}
		else if (height_diff < -1)
		{
			if (ft_compare_height(y) < 0)
				ret_node = ft_rotate_rr(x);
			else
				ret_node = ft_rotate_rl(x);
			if (ret_node)
			{
				if (ret_node->parent == NULL)
					*og_root = ret_node;
				x = ret_node;
				y = x->parent;
				if (x->parent)
					z = x->parent->parent;
				continue;
			}
		}
		x = y;
		y = z;
		z = z->parent;
	}
}

int		ft_compare_height(t_tree *root)
{
	int		left_height;
	int		right_height;

	left_height = 0;
	right_height = 0;
	if (!root)
		return (0);
	if (root->left)
		left_height = ft_get_height(root->left);
	if (root->right)
		right_height = ft_get_height(root->right);
	return (left_height - right_height);
}

int		ft_get_height(t_tree *root)
{
	int		left;
	int		right;

	left = 1;
	right = 1;
	if (!root)
		return (0);
	if (root->left)
		left = ft_get_height(root->left) + 1;
	if (root->right)
		right = ft_get_height(root->right) + 1;
	return (left > right ? left : right);
}