#include "../includes/ft_tree.h"

t_queue	*ft_create_queue(void)
{
	t_queue	*ret;

	if (!(ret = (t_queue *)malloc(sizeof(t_queue))))
	{
		printf("malloc error: ft_create_queue\n");
		return (NULL);
	}
	ret->back = NULL;
	ret->front = NULL;
	ret->count = 0;
	return (ret);
}

t_node	*ft_create_tnode(t_tree	*tree_node)
{
	t_node	*node;

	if (tree_node == NULL)
		return (NULL);
	if (!(node = (t_node *)malloc(sizeof(t_node))))
	{
		printf("malloc error: ft_create_tnode\n");
		return (NULL);
	}
	node->next = NULL;
	node->tree_node = tree_node;
	return (node);
}

void	ft_enqueue(t_queue *queue, t_tree *tree_node)
{
	t_node	*node;

	if (queue == NULL || tree_node == NULL)
		return ;
	if (!(node = ft_create_tnode(tree_node)))
		return ;
	else if (queue->count == 0)
	{
		queue->front = node;
		queue->back = node;
	}
	else
	{
		queue->back->next = node;
		queue->back = node;
	}
	queue->count += 1;
}

t_node	*ft_dequeue(t_queue *queue)
{
	t_node	*ret;

	ret = NULL;
	if (!queue)
		return (NULL);
	else
	{
		ret = queue->front;
		queue->front = ret->next;
	}
	queue->count -= 1;
	return (ret);
}