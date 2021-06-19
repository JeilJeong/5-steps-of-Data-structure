#include "../includes/ft_avl.h"

void	ft_insert_tree_node(t_tree **og_root, t_tree **root, t_tree *node, t_tree *parent, int *count)
{
	if (!node)
		return ;
	if (!(*root))
	{
		*root = node;
		node->parent = parent;
		if (!parent)
			*og_root = node;
		*count += 1;
		ft_insertion_balancing_mode(og_root, node);
		return ;
	}
	if ((*root)->data > node->data)
		ft_insert_tree_node(og_root, &((*root)->left), node, *root, count);
	else if ((*root)->data < node->data)
		ft_insert_tree_node(og_root, &((*root)->right), node, *root, count);
	else if ((*root)->data == node->data)
		free(node);
}