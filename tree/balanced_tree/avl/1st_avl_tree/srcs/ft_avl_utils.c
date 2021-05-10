#include "../includes/ft_avl.h"

t_tree	*ft_find_max(t_tree *root)
{
	if (root->right)
		return (ft_find_max(root->right));
	return (root);
}

void	ft_resolve_height(t_tree *root)
{
	if (!root)
		return ;
	root->height -= 1;
	if (root->left)
		ft_resolve_height(root->left);
	if (root->right)
		ft_resolve_height(root->right);
}

t_tree	*ft_check_insert_balance(t_tree *root)
{
	t_tree	*parent;
	t_tree	*x;
	t_tree	*y;
	t_tree	*z;
	int		height;
	int		check_height;
	int		diff;

	write(1, "3??\n", 4);
	parent = root->parent;
	x = NULL;
	y = NULL;
	z = NULL;
	height = 0;
	check_height = root->height;
	diff = 0;
	while (1)
	{
		write(1, "3!!\n", 4);
		if (!(z = parent))
		{
			break;
		}
		write(1, "3mid\n", 5);
		if (parent->left == root)
		{
			write(1, "left\n", 5);
			height = ft_find_deepest_height(parent->right);
			write(1, "left_2\n", 7);
		}
		else if (parent->right == root)
		{
			write(1, "right\n", 6);
			height = ft_find_deepest_height(parent->left);
		}
		diff = height > check_height ? height - check_height : check_height - height;
		write(1, "3_after diff\n", 13);
		if (diff > 1)
		{
			if (!x || !y)
			{
				x = root;
				y = z;
				z = z->parent;
			}
			printf("height: %d, check_height: %d, diff: %d\n", height, check_height, diff);
			break;
		}
		write(1, "3_break check\n", 14);
		x = y;
		y = z;
		root = parent;
		write(1, "3_before parent\n", 16);
		parent = parent->parent;
		write(1, "3_end\n", 6);
	}
	if (diff > 1)
	{
		return (ft_insert_rebalance(x, y, z));
	}
	return (root);
}

int		ft_find_deepest_height(t_tree *root)
{
	int		l_height;
	int		r_height;

	l_height = 0;
	r_height = 0;
	if (!root)
		return (0);
	else if (!root->left && !root->right)
		return (root->height);
	if (root->left)
		l_height = ft_find_deepest_height(root->left);
	if (root->right)
		r_height = ft_find_deepest_height(root->right);
	return (l_height > r_height ? l_height : r_height);
}

t_tree	*ft_insert_rebalance(t_tree *x, t_tree *y, t_tree *z)
{
	int		sequence_case;

	sequence_case = ft_sequence_case(x, y, z);
	if (sequence_case == 1)
	{
		y->parent = z->parent;
		if (z->parent)
		{
			if (z->parent->left == z)
				z->parent->left = y;
			else if (z->parent->right == z)
				z->parent->right = y;
		}
		z->parent = y;
		if (y->right)
		{
			z->left = y->right;
			z->left->parent = z;
		}
		y->right = z;
		return (y);
	}
	else if (sequence_case == 2)
	{
		y->parent = z->parent;
		if (z->parent)
		{
			if (z->parent->left == z)
				z->parent->left = y;
			else if (z->parent->right == z)
				z->parent->right = y;
		}
		z->parent = y;
		if (y->left)
		{
			z->right = y->left;
			z->right->parent = z;
		}
		y->left = z;
		return (y);
	}
	else if (sequence_case == 3)
	{
		// 1st
		z->left = x;
		x->parent = z;
		if (x->left)
		{
			y->right = x->left;
			y->right->parent = y;
		}
		x->left = y;
		y->parent = x;
		// 2nd
		x->parent = z->parent;
		if (z->parent)
		{
			if (z->parent->left == z)
				z->parent->left = x;
			else if (z->parent->right == z)
				z->parent->right = x;
		}
		if (x->right)
		{
			z->left = x->right;
			z->left->parent = z;
		}
		x->right = z;
		z->parent = x;
		return (x);
	}
	else if (sequence_case == 4)
	{
		// 1st
		z->right = x;
		x->parent = z;
		if (x->right)
		{
			y->left = x->right;
			y->left->parent = y;
		}
		x->right = y;
		y->parent = x;
		// 2nd
		x->parent = z->parent;
		if (z->parent)
		{
			if (z->parent->right == z)
				z->parent->right = x;
			else if (z->parent->left == z)
				z->parent->left = x;
		}
		if (x->left)
		{
			z->right = x->left;
			z->right->parent = z;
		}
		x->left = z;
		z->parent = x;
		return (x);
	}
	return (z);
}

int		ft_sequence_case(t_tree *x, t_tree *y, t_tree *z)
{
	if (z->left == y)
	{
		if (y->left == x)
			return (1);
		return (3);
	}
	else if (z->right == y)
	{
		if (y->right == x)
			return (2);
		return (4);
	}
	return (0);
}