#include "../includes/ft_tree.h"

void	ft_level_node(t_queue *queue, t_tree *root)
{
	if (root == NULL)
		return ;
	else
		ft_enqueue(queue, root);
	if (root->left)
		ft_level_node(queue, root->left);
	if (root->right)
		ft_level_node(queue, root->right);
	
}

void	ft_level_traversal(t_tree *root)
{
	t_queue	*queue;
	t_node	*node;

	queue = ft_create_queue();
	while (root)
	{
		if (root == NULL)
			return ; 
		else
		{
			ft_enqueue(queue, root);
			node = ft_dequeue(queue);
			node->
		}
	}
	ft_level_node(queue, root);
}