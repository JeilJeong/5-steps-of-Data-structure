#include "../includes/ft_avl.h"

void	ft_insertion_balancing_mode(t_tree **og_root, t_tree *node)
{
	int		height_diff;
	t_tree	*x;
	t_tree	*y;
	t_tree	*z;
	t_tree	*ret_node;

	height_diff = 0;
	x = NULL;
	y = NULL;
	z = NULL;
	if (!(*og_root) || !node)
		return ;
	x = node;
	y = x->parent;
	if (x->parent)
		z = x->parent->parent;
	while (x && y && z)
	{
		height_diff = ft_get_height_diff(z);
		if (height_diff > 1)
		{
			if (ft_get_height_diff(y) > 0)
				ret_node = ft_rotate_ll(x);
			else
				ret_node = ft_rotate_lr(x);
			if (ret_node)
			{
				if (!(ret_node->parent))
					*og_root = ret_node;
				x = ret_node;
				y = ret_node->parent;
				if (y)
					z = y->parent;
				else
					z = NULL;
				continue;
			}
		}
		else if (height_diff < -1)
		{
			if (ft_get_height_diff(y) < 0)
				ret_node = ft_rotate_rr(x);
			else
				ret_node = ft_rotate_rl(x);
			if (ret_node)
			{
				if (!(ret_node->parent))
					*og_root = ret_node;
				x = ret_node;
				y = ret_node->parent;
				if (y)
					z = y->parent;
				else
					z = NULL;
				continue;
			}
		}
		x = y;
		y = z;
		z = z->parent;
	}
}

int		ft_get_height_diff(t_tree *center)
{
	int		left_height;
	int		right_height;

	left_height = 0;
	right_height = 0;
	if (!center)
		return (0);
	if (center->left)
		left_height = ft_get_height(center->left);
	if (center->right)
		right_height = ft_get_height(center->right);
	return (left_height - right_height);
}

int		ft_get_height(t_tree *root)
{
	int		left_height;
	int		right_height;

	left_height = 1;
	right_height = 1;
	if (!root)
		return (0);
	if (root->left)
		left_height = ft_get_height(root->left) + 1;
	if (root->right)
		right_height = ft_get_height(root->right) + 1;
	return (left_height > right_height ? left_height : right_height);
}