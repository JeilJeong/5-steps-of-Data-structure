#include "../includes/ft_avl.h"

t_tree	*ft_rotate_rr(t_tree *x, t_tree *y, t_tree *z)
{
	if (!x || !y || !z)
		return (NULL);
	if (z->parent)
	{
		if(z->parent->left == z)
			z->parent->left = y;
		else if (z->parent->right == z)
			z->parent->right = y;
	}
	y->parent = z->parent;
	if (y->right)
	{
		z->left = y->right;
		z->left->parent = z;
	}
	else
		z->left = NULL;
	y->right = z;
	z->parent = y;
	ft_resolve_height(y, z->height);
	return (y);
}

t_tree	*ft_rotate_ll(t_tree *x, t_tree *y, t_tree *z)
{
	if (!x || !y || !z)
		return (NULL);
	if (z->parent)
	{
		if (z->parent->left == z)
			z->parent->left = y;
		else if (z->parent->right == z)
			z->parent->right = y;
	}
	y->parent = z->parent;
	if (y->left)
	{
		z->right = y->left;
		z->right->parent = z;
	}
	else
		z->right = NULL;
	y->left = z;
	z->parent = y;
	ft_resolve_height(y, z->height);
	return (y);
}

t_tree	*ft_rotate_lr(t_tree *x, t_tree *y, t_tree *z)
{
	if (x->left)
	{
		y->right = x->left;
		y->right->parent = y;
	}
	else
		y->right = NULL;
	x->left = y;
	y->parent = x;
	if (z->parent)
	{
		if (z->parent->left == z)
			z->parent->left = x;
		else if (z->parent->right == z)
			z->parent->right = x;
	}
	x->parent = z->parent;
	if (x->right)
	{
		z->left = x->right;
		z->left->parent = z;
	}
	else
		z->left = NULL;
	x->right = z;
	z->parent = x;
	ft_resolve_height(x, z->height);
	return (x);
}

t_tree	*ft_rotate_rl(t_tree *x, t_tree *y, t_tree *z)
{
	if (x->right)
	{
		y->left = x->right;
		y->left->parent = x;
	}
	else
		y->left = NULL;
	x->right = y;
	y->parent = x;
	if (z->parent)
	{
		if (z->parent->left == z)
			z->parent->left = x;
		else if (z->parent->right == z)
			z->parent->right = x;
	}
	x->parent = z->parent;
	if (x->left)
	{
		z->right = x->left;
		z->right->parent = z;
	}
	else
		z->right = NULL;
	x->left = z;
	z->parent = x;
	ft_resolve_height(x, z->height);
	return (x);
}

void	ft_resolve_height(t_tree *root, int height)
{
	if (!root)
		return ;
	root->height = height;
	if (root->left)
		ft_resolve_height(root->left, height + 1);
	if (root->right)
		ft_resolve_height(root->right, height + 1);
}