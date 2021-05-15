#include "../includes/ft_avl.h"

int		ft_insert_tree_node(t_tree **og_root, t_tree **root, t_tree *node, t_tree *parent, int height)
{
	if (!node)
		return (0);
	if (!(*root))
	{
		*root = node;
		node->height = height;
		node->parent = parent;
		ft_balance_check_insertion_mode(og_root, *root);
		return (1);
	}
	if ((*root)->data > node->data)
		return (ft_insert_tree_node(og_root, &((*root)->left), node, *root, height + 1));
	else if ((*root)->data < node->data)
		return (ft_insert_tree_node(og_root, &((*root)->right), node, *root, height + 1));
	return (0);
}