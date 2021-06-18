#include "../includes/ft_avl.h"

t_tree	*ft_insert_tree_node(t_tree **og_root, t_tree *root, t_tree *node, t_tree *parent, int *count)
{
	if (!node)
		return ;
	if (!root)
	{
		root = node;
		node->parent = parent;
		if (!parent)
			*og_root = node;
		*count += 1;
		return (node);
	}
	if (root->data > node->data)
		root->left = ft_insert_tree_node(og_root, root->left, node, root, count);
	else if (root->data < node->data)
		root->right = ft_insert_tree_node(og_root, root->right, node, root, count);
	else if (root->data == node-> data)
		free(node);
	return (root);
}