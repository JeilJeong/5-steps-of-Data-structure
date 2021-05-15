#include "../includes/ft_avl.h"

t_queue	*ft_create_queue(void)
{
	t_queue		*ret;

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

void	ft_enqueue(t_queue *queue, t_tree *tree_node)
{
	t_node	*node;

	if (!queue || !tree_node)
		return ;
	while (!(node = ft_create_node(tree_node)))
		printf("alloc error: ft_enqueue\n");
	if (queue->count == 0)
	{
		queue->front = node;
		queue->back = node;
		queue->count += 1;
	}
	else
	{
		queue->back->next = node;
		queue->back = node;
		queue->count += 1;
	}
}

t_node	*ft_dequeue(t_queue *queue)
{
	t_node	*ret;

	if (!queue)
		return (NULL);
	if (!(ret = queue->front))
		return (ret);
	queue->front = ret->next;
	queue->count -= 1;
	return (ret);
}

t_node	*ft_create_node(t_tree *tree_node)
{
	t_node	*ret;

	if (!tree_node)
		return (NULL);
	if (!(ret = (t_node *)malloc(sizeof(t_node))))
	{
		printf("malloc error: ft_create_node\n");
		return (ret);
	}
	ret->next = NULL;
	ret->tree_node = tree_node;
	return (ret);
}