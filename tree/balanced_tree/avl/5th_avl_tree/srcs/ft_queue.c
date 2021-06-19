#include "../includes/ft_avl.h"

t_queue	*ft_create_queue(void)
{
	t_queue *ret;

	while (!(ret = (t_queue *)malloc(sizeof(t_queue))))
		printf("malloc error: ft_create_queue\n");
	ret->count = 0;
	ret->front = NULL;
	ret->back = NULL;
	return (ret);
}

t_node	*ft_create_s_node(t_tree *node)
{
	t_node *ret;

	if (!node)
		return (NULL);
	while (!(ret = (t_node *)malloc(sizeof(t_node))))
		printf("malloc error: ft_create_s_node\n");
	ret->next = NULL;
	ret->tree_node = node;
	return (ret);
}

void	ft_enqueue(t_queue *queue, t_tree *node)
{
	t_node	*ret;

	ret = NULL;
	if (!queue || !node)
		return ;
	while (!(ret = ft_create_s_node(node)))
		printf("alloc error: ft_enqueue\n");
	if (queue->count == 0)
	{
		queue->front = ret;
		queue->back = ret;
		queue->count += 1;
	}
	else
	{
		queue->back->next = ret;
		queue->back = ret;
		queue->count += 1;
	}
}

t_node	*ft_dequeue(t_queue *queue)
{
	t_node	*ret;

	ret = NULL;
	if (!queue)
		return (NULL);
	if((ret = queue->front))
	{
		queue->front = ret->next;
		queue->count -= 1;
	}
	return (ret);
}