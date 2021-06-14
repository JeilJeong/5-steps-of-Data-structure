#include "../includes/ft_avl.h"

void	ft_traversal_level_mode(t_tree *root)
{
	t_queue *queue;
	t_node	*node;

	queue = NULL;
	node = NULL;
	if (!root)
		return ;
	queue = ft_create_queue();
	ft_enqueue(queue, root);
	printf("	Level Traversal: ");
	while (queue->front)
	{
		if (!(node = ft_dequeue(queue)))
		{
			printf("	function error: ft_dequeue << ft_traversal_level_mode\n");
			return ;
		}
		if (node->tree_node)
			printf("%d ", node->tree_node->data);
		if (node->tree_node->left)
			ft_enqueue(queue, node->tree_node->left);
		if (node->tree_node->right)
			ft_enqueue(queue, node->tree_node->right);
		free(node);
	}
	ft_println(1);
	free(queue);
}

t_queue	*ft_create_queue(void)
{
	t_queue *ret;

	while (!(ret = (t_queue *)malloc (sizeof(t_queue))))
		printf("	malloc error: ft_create_queue\n");
	ret->count = 0;
	ret->front = NULL;
	ret->back = NULL;
	return (ret);
}

void	ft_enqueue(t_queue *queue, t_tree *tree_node)
{
	t_node *node;

	node = NULL;
	if (!queue || !tree_node)
		return ;
	while (!(node = ft_create_queue_node(tree_node)))
		printf("	alloc error: ft_enqueue\n");
	if (queue->count == 0)
	{
		queue->front = node;
		queue->back = node;
		queue->count += 1;
	}
	else if (queue->back)
	{
		queue->back->next = node;
		queue->back = node;
		queue->count += 1;
	}
}

t_node *ft_dequeue(t_queue *queue)
{
	t_node	*ret;

	ret = NULL;
	if (!queue)
		return (NULL);
	if (queue->front)
	{
		ret = queue->front;
		queue->front = ret->next;
		queue->count -= 1;
		return (ret);
	}
	return (NULL);
}

t_node *ft_create_queue_node(t_tree *tree_node)
{
	t_node *ret;
	
	if (!tree_node)
		return (NULL);
	while (!(ret = (t_node *)malloc(sizeof(t_node))))
		printf("	malloc error: ft_create_queue_node\n");
	ret->next = NULL;
	ret->tree_node = tree_node;
	return (ret);
}