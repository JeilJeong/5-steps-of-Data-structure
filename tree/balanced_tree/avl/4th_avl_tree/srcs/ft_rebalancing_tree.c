#include "../includes/ft_avl.h"

void	ft_rebalancing_tree(t_tree **og_root, t_tree *node)
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
	z = node;
	while (z)
	{
		height_diff = ft_compare_height(z);
		if (height_diff > 1)
		{
			y = z->left;
			if (ft_compare_height(y) > 0)
			{
				if (y->left)
					x = y->left;
				ret_node = ft_rotate_ll(x);
			}
			else
			{
				x = y->right;
				ret_node = ft_rotate_lr(x);
			}
			if (ret_node)
			{
				if (ret_node->parent == NULL)
					*og_root = ret_node;
				z = ret_node->parent;
				continue;
			}
		}
		else if (height_diff < -1)
		{
			y = z->right;
			if (ft_compare_height(y) < 0)
			{
				x = y->right;
				ret_node = ft_rotate_rr(x);
			}
			else
			{
				x = y->left;
				ret_node = ft_rotate_rl(x);
			}
			if (ret_node)
			{
				if (ret_node->parent == NULL)
					*og_root = ret_node;
				z = ret_node->parent;
				continue;
			}
		}
		z = z->parent;
	}
}