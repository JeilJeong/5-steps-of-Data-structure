#include "../includes/ft_avl.h"

void	ft_remove_tree_mode(t_tree **og_root, int *count)
{
	if (!(*og_root))
		return ;
	*og_root = ft_remove_tree(*og_root, count);
	if (!(*og_root))
		printf("Tree has been deleted\n");
	printf("Count: %d\n", *count);
}

t_tree	*ft_remove_tree(t_tree *root, int *count)
{
	if (!root)
		return (NULL);
	if (root->left)
		root->left = ft_remove_tree(root->left, count);
	if (root->right)
		root->right = ft_remove_tree(root->right, count);
	if (!root->left && !root->right)
	{
		free(root);
		root = NULL;
		*count -= 1;
	}
	return (root);
}
