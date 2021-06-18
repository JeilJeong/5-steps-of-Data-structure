#include "../includes/ft_avl.h"

t_tree	*ft_create_tree_node(int data)
{
	t_tree	*ret;

	while (!(ret = (t_tree *)malloc(sizeof(t_tree))))
		printf("	malloc error: ft_create_tree_node\n");
	ret->data = data;
	ret->parent = NULL;
	ret->left = NULL;
	ret->right = NULL;
}