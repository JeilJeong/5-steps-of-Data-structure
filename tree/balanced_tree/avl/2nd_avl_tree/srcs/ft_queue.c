#include "../includes/ft_avl.h"

t_queue	*ft_create_queue(void)
{
	t_queue		*ret;

	if (!(ret = (t_queue *)malloc(sizeof(t_queue))))
	{
		printf("malloc error: ft_create_queue\n");
		return (NULL);
	}
	ret->count = 0;
	ret->back = NULL;
	ret->front = NULL;
	return (ret);
}

t_node	*ft_create_queue_node(t_tree *tree_node)
{
	t_node	*ret;

	if (!tree_node)
		return (NULL);
	if (!(ret = (t_node *)malloc(sizeof(t_node))))
	{
		printf("malloc error: ft_create_queue_node\n");
		return (NULL);
	}
	ret->next = NULL;
	ret->tree_node = tree_node;
	return (ret);
}

void	ft_enqueue(t_queue *queue, t_tree *tree_node)
{
	t_node	*node;

	if (!tree_node)
		return ;
	if (!(node = ft_create_queue_node(tree_node)))
	{
		printf("alloc error: ft_enqueue\n");
		return ;
	}
	if (!queue->front)
		queue->front = node;
	if (queue->back)
		queue->back->next = node;
	queue->back = node;
	queue->count += 1;
}

t_node	*ft_dequeue(t_queue *queue)
{
	t_node	*ret;

	if (!queue)
		return (NULL);
	if (queue->front)
	{
		ret = queue->front;
		queue->front = queue->front->next;
		queue->count -= 1;
		return (ret);
	}
	return (queue->front);
}