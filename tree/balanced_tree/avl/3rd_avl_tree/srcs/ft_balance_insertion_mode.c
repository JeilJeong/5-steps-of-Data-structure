#include "../includes/ft_avl.h"

void	ft_balance_check_insertion_mode(t_tree **og_root, t_tree *root)
{
	int		l_height;
	int		r_height;
	int		diff;
	t_tree	*x;
	t_tree	*y;
	t_tree	*z;
	t_tree	*ret;

	l_height = -1;
	r_height = -1;
	diff = 0;
	x = NULL;
	if (!(y = root))
		return ;
	z = y->parent;
	while (z)
	{
		if ((l_height = ft_find_deep(z->left)) < 0)
			l_height = z->height;
		if ((r_height = ft_find_deep(z->right)) < 0)
			r_height = z->height;
		diff = l_height > r_height ? l_height - r_height : r_height - l_height;
		if (diff > 1)
		{
			ret = ft_rebalancing_insertion_mode(x, y, z);
			if (ret)
			{
				if (ret->height == 0)
					*og_root = ret;
			}
			return ;
		}
		x = y;
		y = z;
		z = z->parent;
	}
}

t_tree	*ft_rebalancing_insertion_mode(t_tree *x, t_tree *y, t_tree *z)
{
	int		sequence_case;

	sequence_case = 0;
	if (!x || !y || !z)
		return (NULL);
	sequence_case = ft_xyz_sequence_case(x, y, z);
	if (sequence_case == 1)
	{
		printf("	[case 1] rotate_rr occurred\n");
		return (ft_rotate_rr(x, y, z));
	}
	else if (sequence_case == 2)
	{
		printf("	[case 2] rotate_ll occurred\n");
		return (ft_rotate_ll(x, y, z));
	}
	else if (sequence_case == 3)
	{
		printf("	[case 3] rotate_lr occurred\n");
		return (ft_rotate_lr(x, y, z));
	}
	else if (sequence_case == 4)
	{
		printf("	[case 4] rotate_rl occurred\n");
		return (ft_rotate_rl(x, y, z));
	}
	printf("	[case 0] \n");
	return (z);
}

int		ft_xyz_sequence_case(t_tree *x, t_tree *y, t_tree *z)
{
	if (z->left == y)
	{
		if (y->left == x)
			return (1);
		else if (y->right == x)
			return (3);
	}
	else if (z->right == y)
	{
		if (y->right == x)
			return (2);
		else if (y->left == x)
			return (4);
	}
	return (0);
}

int		ft_find_deep(t_tree *root)
{
	int		l_height;
	int		r_height;

	l_height = -1;
	r_height = -1;
	if (!root)
		return (-1);
	if (root->left)
		l_height = ft_find_deep(root->left);
	if (root->right)
		r_height = ft_find_deep(root->right);
	if (!root->left && !root->right)
		return (root->height);
	return (l_height > r_height ? l_height : r_height);
}