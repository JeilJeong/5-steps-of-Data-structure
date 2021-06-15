#include "../includes/ft_avl.h"

t_tree	*ft_rotate_ll(t_tree *x)
{
	t_tree	*y;
	t_tree	*z;

	y = NULL;
	z = NULL;
	if (!x)
		return (x);
	if (x->parent)
		y = x->parent;
	if (x->parent->parent)
		z = x->parent->parent;
	if (x && y && z)
	{
		if (z->parent)
		{
			if (z->parent->left == z)
				z->parent->left = y;
			else if (z->parent->right == z)
				z->parent->right = y;
		}
		y->parent = z->parent;
		if (y->right)
			y->right->parent = z;
		z->left = y->right;
		y->right = z;
		z->parent = y;
		return (y);
	}
	return (z);
}
t_tree	*ft_rotate_lr(t_tree *x)
{
	t_tree	*y;
	t_tree	*z;

	y = NULL;
	z = NULL;
	if (!x)
		return (x);
	if (x->parent)
		y = x->parent;
	if (x->parent->parent)
		z = x->parent->parent;
	if (x && y && z)
	{
		y->right = x->left;
		if (x->left)
			x->left->parent = y;
		x->left = y;
		y->parent = x;
		x->parent = z;
		z->left = x;
		return (ft_rotate_ll(y));
	}
	return (z);
}

t_tree	*ft_rotate_rr(t_tree *x)
{
	t_tree	*y;
	t_tree	*z;

	y = NULL;
	z = NULL;
	if (!x)
		return (x);
	if (x->parent)
		y = x->parent;
	if (x->parent->parent)
		z = x->parent->parent;
	if (x && y && z)
	{
		if (z->parent)
		{
			if (z->parent->left == z)
				z->parent->left = y;
			else if (z->parent->right == z)
				z->parent->right = y;
		}
		y->parent = z->parent;
		if (y->left)
			y->left->parent = z;
		z->right = y->left;
		y->left = z;
		z->parent = y;
		return (y);
	}
	return (z);
}

t_tree	*ft_rotate_rl(t_tree *x)
{
	t_tree	*y;
	t_tree	*z;

	y = NULL;
	z = NULL;
	if (!x)
		return (x);
	if (x->parent)
		y = x->parent;
	if (x->parent->parent)
		z = x->parent->parent;
	if (x && y && z)
	{
		y->left = x->right;
		if (x->right)
			x->right->parent = y;
		y->parent = x;
		x->right = y;
		x->parent = z;
		z->right = x;
		return (ft_rotate_rr(y));
	}
	return (z);
}