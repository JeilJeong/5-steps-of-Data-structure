#include "../includes/ft_avl.h"

void	ft_insert_tree_node(t_tree **og_root, t_tree **root, t_tree *node, t_tree *parent, int height)
{
	if (!node)
		return ;
	if (!(*root))
	{
		*root = node;
		node->height = height;
		node->parent = parent;
		ft_balance_check_insertion_mode(og_root, *root);
	}
	if ((*root)->data >= node->data)
		ft_insert_tree_node(og_root, &((*root)->left), node, root, height + 1);
	else if ((*root)->data < node->data)
		ft_insert_tree_node(og_root, &((*root)->right), node, root, height + 1);
}