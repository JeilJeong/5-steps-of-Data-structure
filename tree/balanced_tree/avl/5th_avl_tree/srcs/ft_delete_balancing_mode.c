#include "../includes/ft_avl.h"

void	ft_deletion_balancing_mode(t_tree **og_root, t_retNode *ret_node)
{
	t_tree	*y;
	t_tree	*z;
	t_tree	*new_root;
	int		height_diff;

	y = NULL;
	z = NULL;
	height_diff = 0;
	if (!(*og_root) || !ret_node)
		return ;
	if (!(z = ret_node->ret_bal))
		return ;
	while (z)
	{
		height_diff = ft_get_height_diff(z);
		if (height_diff > 1)
		{
			y = z->left;
			if (ft_get_height_diff(y) > 0)
				new_root = ft_rotate_ll(y->left);
			else
				new_root = ft_rotate_lr(y->right);
			if (new_root)
			{
				if (!new_root->parent)
					*og_root = new_root;
				z = new_root->parent;
				continue;
			}
		}
		else if (height_diff < -1)
		{
			y = z->right;
			if (ft_get_height_diff(y) < 0)
				new_root = ft_rotate_rr(y->right);
			else
				new_root = ft_rotate_rl(y->left);
			if (new_root)
			{
				if (!new_root->parent)
					*og_root = new_root;
				z = new_root->parent;
				continue;
			}
		}
		z = z->parent;
	}
}