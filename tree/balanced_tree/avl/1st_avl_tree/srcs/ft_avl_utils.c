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