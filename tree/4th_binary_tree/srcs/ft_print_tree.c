#include "../includes/ft_tree.h"

void	ft_print_tree(t_tree *root)
{
	if (root == NULL)
		return ;
	else
	{
		ft_print_tree(root->left);
		printf("%d ", root->data);
		ft_print_tree(root->right);
	}
}

void	ft_level_traversal(t_tree *root)
{
	t_node		*node;
	t_queue		*queue;

	node = NULL;
	queue = NULL;
	if (root == NULL)
		return ;
	else
	{
		queue = ft_create_queue();
		ft_enqueue(queue, root);
		while (queue->front != NULL)
		{
			node = ft_dequeue(queue);
			printf("%d ", node->tree_node->data);
			if (node->tree_node->left)
				ft_enqueue(queue, node->tree_node->left);
			if (node->tree_node->right)
				ft_enqueue(queue, node->tree_node->right);
			free(node);
		}
		free(queue);
	}
}