#include "../includes/ft_tree.h"

void	ft_search_tree_node(t_tree *root, int data, int level)
{
	if (!root)
	{
		printf("[%d] doesn't exist in the tree", data);
	}
	else if (root->data == data)
	{
		printf("<level:%d> [%d] exists in the tree", level, data);
	}
	else if (root->data > data)
		ft_search_tree_node(root->left, data, level + 1);
	else if (root->data < data)
		ft_search_tree_node(root->right, data, level + 1);
	return ;
}

t_tree	*ft_search_max_node(t_tree *root)
{
	if (!root->right)
		return (root);
	return (ft_search_max_node(root->right));
}