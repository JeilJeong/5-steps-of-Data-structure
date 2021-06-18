#include "../includes/ft_avl.h"

void	ft_search_tree_mode(t_tree *root, t_tree *node)
{
	int		data;
	t_tree	*ret;

	data = 0;
	ret = NULL;
	if (!root || !node)
		return ;
	while (1)
	{
		ft_println(1);
		printf("+++[Search Mode]+++\n");
		printf("Type Data: ");
		scanf("%d", data);
		ret = ft_search_tree_node(root, node);
		if (ret)
		{
			printf("[%d] == Exist\n", data);
			if (ret->parent)
				printf("[Parent] == %d\n", ret->parent->data);
			else
				printf("[Parent] == NULL\n");
			if (ret->left)
				printf("[Left] == %d\n", ret->left->data);
			else
				printf("[Left] == NULL\n");
			if (ret->right)
				printf("[Right] == %d\n", ret->right->data);
			else
				printf("[Right] == NULL\n");
		}
		else
			printf("[%d] == NULL\n", data);
	}
}

t_tree	*ft_search_tree_node(t_tree *root, t_tree *node)
{
	t_tree	*ret;

	ret = NULL;
	if (!root || !node)
		return (ret);
	if (root->data == node->data)
		ret = root;
	else if (root->data > node->data)
		ret = ft_search_tree_node(root->left, node);
	else if (root->data < node->data)
		ret = ft_search_tree_node(root->right, node);
	return (ret);
}