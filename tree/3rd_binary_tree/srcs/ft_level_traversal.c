#include "../includes/ft_tree.h"

void	ft_level_traversal(t_tree *root)
{
	t_queue	*queue;
	t_tree	*tree_node;
	t_node	*node;

	queue = ft_create_queue();
	if (root == NULL)
		return ;
	else
	{
		ft_enqueue(queue, root);
		printf("\n	Level Traversal: ");
		while (queue->front != NULL)
		{
			node = ft_dequeue(queue);
			tree_node = node->tree_node;
			printf("%d ", tree_node->data);
			if (tree_node->left)
				ft_enqueue(queue, tree_node->left);
			if (tree_node->right)
				ft_enqueue(queue, tree_node->right);
		}
		ft_println(1);
	}
}