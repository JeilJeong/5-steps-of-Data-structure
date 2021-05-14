#include "../includes/ft_avl.h"

t_tree	*ft_create_tree_node(int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree *)malloc(sizeof(t_tree))))
	{
		printf("malloc error: ft_create_tree_node\n");
		return (NULL);
	}
	ret->data = data;
	ret->height = 0;
	ret->parent = NULL;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}