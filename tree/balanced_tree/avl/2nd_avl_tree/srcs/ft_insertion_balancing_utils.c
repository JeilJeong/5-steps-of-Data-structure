#include "../includes/ft_avl.h"

void	ft_balance_check_insert_mode(t_tree **og_root, t_tree *root, int height)
{
	int		anti_height;
	int 	diff;
	t_tree	*x;
	t_tree	*y;
	t_tree	*z;
	t_tree	*ret;

	anti_height = 0;
	diff = 0;
	x = NULL;
	y = root;
	z = root->parent;
	ret = NULL;
	while (z)
	{
		if (z->left == y)
		{
			if (!z->right)
				anti_height = z->height;
			else
				anti_height = ft_find_max_deep(z->right);
		}
		else if (z->right == y)
		{
			if (!z->left)
				anti_height = z->height;
			else
				anti_height = ft_find_max_deep(z->left);
		}
		diff = anti_height > height ? anti_height - height : height - anti_height;
		if (diff > 1)
		{
			if (!(ret = ft_rebalancing_insert_mode(x, y, z)))
			{
				printf("	message: rebalancing already has done\n");
				return ;
			}
			if (!ret->parent)
				*og_root = ret;
			return ;
		}
		x = y;
		y = z;
		z = y->parent;
	}
}

t_tree	*ft_rebalancing_insert_mode(t_tree *x, t_tree *y, t_tree *z)
{
	int		re_case;

	re_case = 0;
	if (!x || !y || !z)
		return (NULL);
	re_case = ft_rebalancing_case_insert_mode(x, y, z);
	if (re_case == 1)
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
		{
			z->left = y->right;
			z->left->parent = z;
		}
		else
			z->left = NULL;
		y->right = z;
		z->parent = y;
		ft_resolve_height_down(y, z->height);
		return (y);
	}
	else if (re_case == 2)
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
		{
			z->right = y->left;
			z->right->parent = z;
		}
		else
			z->right = NULL;
		y->left = z;
		z->parent = y;
		ft_resolve_height_down(y, z->height);
		return (y);
	}
	else if (re_case == 3)
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
		if (x->right)
		{
			z->left = x->right;
			z->left->parent = z;
		}
		else
			z->left = NULL;
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
		ft_resolve_height_down(x, z->height);
		return (x);
	}
	else if (re_case == 4)
	{
		if (x->right)
		{
			y->left = x->right;
			y->left->parent = y;
		}
		else
			y->left = NULL;
		x->right = y;
		y->parent = x;
		if (x->left)
		{
			z->right = x->left;
			z->right->parent = x;
		}
		else
			z->right = NULL;
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
		ft_resolve_height_down(x, z->height);
		return (x);
	}
	return (z);
}

int		ft_rebalancing_case_insert_mode(t_tree *x, t_tree *y, t_tree *z)
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

int		ft_find_max_deep(t_tree *root)
{
	int		l_height;
	int		r_height;

	l_height = 0;
	r_height = 0;
	if (!root)
		return (0);
	if (!root->left && !root->right)
		return (root->height);
	if (root->left)
		l_height = ft_find_max_deep(root->left);
	if (root->right)
		r_height = ft_find_max_deep(root->right);
	return (l_height > r_height ? l_height : r_height);
}

void	ft_resolve_height_down(t_tree *root, int height)
{
	if (!root)
		return ;
	root->height = height;
	if (root->left)
		ft_resolve_height_down(root->left, height + 1);
	if (root->right)
		ft_resolve_height_down(root->right, height + 1);
}
