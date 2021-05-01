#include "../includes/ft_avl.h"

void	ft_println(int size)
{
	while (--size >= 0)
		printf("\n");
}

int		ft_print_tree(t_tree *root, int order)
{
	int		ret;

	ret = NORMAL;
	if (!root)
		return (ret);
	else if (order == PRE_ORDER)
	{
		printf("%d ", root->data);
		ret = ft_print_tree(root->left, order);
		ret = ft_print_tree(root->right, order);
	}
	else if (order == IN_ORDER)
	{
		ret = ft_print_tree(root->left, order);
		printf("%d ", root->data);
		ret = ft_print_tree(root->right, order);
	}
	else if (order == POST_ORDER)
	{
		ret = ft_print_tree(root->left, order);
		ret = ft_print_tree(root->right, order);
		printf("%d ", root->data);
	}
	else if (order == LEVEL)
		ret = ft_print_level(root);
	return (ret);
}

int		ft_print_level(t_tree *root)
{
	t_node		*node;
	t_queue		*queue;

	if (!root)
		return (ABNORMAL);
	if (!(queue = ft_create_queue()))
	{
		printf("alloc error: ft_print_level");
		ft_println(1);
		return (ABNORMAL);
	}
	if (ft_enqueue(queue, root) == ABNORMAL)
		return (ABNORMAL);
	while (queue->front != NULL)
	{
		if (!(node = ft_dequeue(queue)))
		{
			printf("dequeue error: ft_print_level");
			ft_println(1);
			return (ABNORMAL);
		}
		if (node->tree_node)
		{
			printf("%d ", node->tree_node->data);
			if (node->tree_node->left)
			{
				if (ft_enqueue(queue, node->tree_node->left) == ABNORMAL)
					return (ABNORMAL);
			}
			if (node->tree_node->right)
			{
				if (ft_enqueue(queue, node->tree_node->right) == ABNORMAL)
					return (ABNORMAL);
			}
		}
		free(node);
	}
	free(queue);
	return (NORMAL);
}