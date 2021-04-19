#include "../includes/ft_tree.h"

t_queue	*ft_create_queue(void)
{
	t_queue		*ret;

	ret = NULL;
	if (!(ret = (t_queue *)malloc(sizeof(t_queue))))
	{
		printf("malloc error: ft_create_queue\n");
		return (ret);
	}
	ret->count = 0;
	ret->front = NULL;
	ret->back = NULL;
	return (ret);
}

t_node	*ft_create_queue_node(t_tree *tree_node)
{
	t_node	*ret;

	ret = NULL;
	if (tree_node == NULL)
		return (ret);
	else
	{
		if (!(ret = (t_node *)malloc(sizeof(t_node))))
		{
			printf("malloc error: ft_create_queue_node\n");
			return (ret);
		}
		ret->next = NULL;
		ret->tree_node = tree_node;
	}
	return (ret);
}

void	ft_enqueue(t_queue *queue, t_tree *tree_node)
{
	t_node	*node;

	node = NULL;
	if (tree_node == NULL)
		return ;
	else
	{
		if (!(node = ft_create_queue_node(tree_node)))
			return ;
	}
	if (queue->count == 0)
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
	if (queue->count == 0)
		return (ret);
	else
	{
		ret = queue->front;
		queue->front = ret->next;
		queue->count -= 1;
	}
	return (ret);
}