#include "../includes/ft_avl.h"

void	ft_balance_check_deletion_mode(t_tree **og_root, t_tree *root)
{
	int 	diff;
	int		height;
	int		anti_height;
	t_tree	*temp_root;
	t_tree	*x;
	t_tree	*y;
	t_tree	*z;
	t_tree	*ret;

	if (!(*og_root) || !root)
		return ;
	diff = 0;
	height = -1;
	anti_height = -1;
	temp_root = root;
	x = NULL;
	y = NULL;
	z = NULL;
	while (temp_root)
	{
		if ((height = ft_check_deep(temp_root->left)) < 0)
			height = temp_root->height;
		if ((anti_height = ft_check_deep(temp_root->right)) < 0)
			anti_height = temp_root->height;
		diff = anti_height > height ? anti_height - height : height - anti_height;
		if (diff > 1)
		{
			z = temp_root;
			if ((y = ft_find_xyz_deletion_mode(z)))
			{
				if ((x = ft_find_xyz_deletion_mode(y)))
				{
					ret = ft_rebalancing_insert_mode(x, y, z);
					if (!ret->parent)
						*og_root = ret;
				}
			}
		}
		temp_root = temp_root->parent;
	}
}

t_tree	*ft_find_xyz_deletion_mode(t_tree *root)
{
	int		l_deep;
	int		r_deep;
	t_tree	*ret;

	ret = NULL;
	l_deep = -1;
	r_deep = -1;
	if (!root)
		return (ret);
	if ((l_deep = ft_check_deep(root->left)) < 0)
		l_deep = root->height;
	if ((r_deep = ft_check_deep(root->right)) < 0)
		r_deep = root->height;
	if (l_deep >= r_deep)
		return (root->left);
	else
		return (root->right);
	return (ret);
}

int		ft_check_deep(t_tree *root)
{
	int		l_height;
	int		r_height;

	l_height = -1;
	r_height = -1;
	if (!root)
		return (-1);
	if (!root->left && !root->right)
		return (root->height);
	if (root->left)
		l_height = ft_check_deep(root->left);
	if (root->right)
		r_height = ft_check_deep(root->right);
	return (l_height >= r_height ? l_height : r_height);
}