#include "../includes/ft_avl.h"

t_queue	*ft_create_queue(void)
{
	t_queue		*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
	{
		printf("malloc error: ft_print_level");
		ft_println(1);
		return (NULL);
	}
	queue->count = 0;
	queue->front = NULL;
	queue->back = NULL;
	return (queue);
}

int		ft_enqueue(t_queue *queue, t_tree *tree_node)
{
	t_node	*node;

	if (!queue || !tree_node)
		return (ABNORMAL);
	if (!(node = ft_create_queue_node(tree_node)))
	{
		printf("alloc error: ft_enqueue");
		ft_println(1);
		return (ABNORMAL);
	}
	if (queue->count == 0)
	{
		queue->front = node;
		queue->back = node;
		queue->count += 1;
	}
	else if (queue->count > 0)
	{
		queue->back->next = node;
		queue->back = node;
		queue->count += 1;
	}
	return (NORMAL);
}

t_node	*ft_create_queue_node(t_tree *tree_node)
{
	t_node	*node;

	if (!tree_node)
		return (NULL);
	if (!(node = (t_node *)malloc(sizeof(t_node))))
	{
		printf("malloc error: ft_create_queue_node");
		ft_println(1);
		return (NULL);
	}
	node->next = NULL;
	node->tree_node = tree_node;
	return (node);
}

t_node	*ft_dequeue(t_queue *queue)
{
	t_node	*node;

	if (!queue || queue->count == 0)
		return (NULL);
	node = queue->front;
	queue->front = node->next;
	queue->count -= 1;
	return (node);
}