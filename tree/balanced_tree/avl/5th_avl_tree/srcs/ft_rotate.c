#include "../includes/ft_avl.h"

t_tree	*ft_rotate_ll(t_tree *x)
{
	t_tree *y;
	t_tree *z;

	y = NULL;
	z = NULL;
	if (!x)
		return (NULL);
	y = x->parent;
	if (x->parent)
	{
		z = x->parent->parent;
		if (x && y && z)
		{
			if (z->parent)
			{
				if (z->parent->right == z)
					z->parent->right = y;
				else if (z->parent->left == z)
					z->parent->left = y;
			}
			y->parent = z->parent;
			if (y->right)
				y->right->parent = z;
			z->left = y->right;
			y->right = z;
			z->parent = y;
		}
	}
	return (y);
}

t_tree	*ft_rotate_lr(t_tree *x)
{
	t_tree *y;
	t_tree *z;

	y = NULL;
	z = NULL;
	if (!x)
		return (NULL);
	y = x->parent;
	if (x->parent)
	{
		z = x->parent->parent;
		if (x && y && z)
		{
			if (x->left)
				x->left->parent = y;
			y->right = x->left;
			x->left = y;
			y->parent = x;
			if (x->right)
				x->right->parent = z;
			z->left = x->right;
			if (z->parent)
			{
				if (z->parent->left == z)
					z->parent->left = x;
				else if (z->parent->right == z)
					z->parent->right = x;
			}
			x->parent = z->parent;
			x->right = z;
			z->parent = x;
		}
	}
	return (x);
}

t_tree	*ft_rotate_rr(t_tree *x)
{
	t_tree *y;
	t_tree *z;

	y = NULL;
	z = NULL;
	if (!x)
		return (NULL);
	y = x->parent;
	if (x->parent)
	{
		z = x->parent->parent;
		if (x && y && z)
		{
			if (z->parent)
			{
				if (z->parent->right == z)
					z->parent->right = y;
				else if (z->parent->left == z)
					z->parent->left = y;
			}
			y->parent = z->parent;
			if (y->left)
				y->left->parent = z;
			z->right = y->left;
			y->left = z;
			z->parent = y;
		}
	}
	return (y);
}

t_tree	*ft_rotate_rl(t_tree *x)
{
	t_tree *y;
	t_tree *z;

	y = NULL;
	z = NULL;
	if (!x)
		return (NULL);
	y = x->parent;
	if (x->parent)
	{
		z = x->parent->parent;
		if (x && y && z)
		{
			if (x->right)
				x->right->parent = y;
			y->left = x->right;
			x->right = y;
			y->parent = x;
			if (x->left)
				x->left->parent = z;
			z->right = x->left;
			if (z->parent)
			{
				if (z->parent->left == z)
					z->parent->left = x;
				else if (z->parent->right == z)
					z->parent->right = x;
			}
			x->parent = z->parent;
			x->left = z;
			z->parent = x;
		}
	}
	return (x);
}