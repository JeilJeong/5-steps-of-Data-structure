#include "../includes/ft_avl.h"

t_tree	*ft_find_max(t_tree *root)
{
	if (root->right)
		return (ft_find_max(root->right));
	return (root);
}