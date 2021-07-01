#include "../includes/ft_graph.h"

void	ft_bfs_all(t_graph *graph)
{
	int		i;
	int		*visit;
	t_queue *queue;

	if (!graph)
		return ;
	if (!(visit = (int *)calloc(graph->used_vertex, sizeof(int))))
	{
		printf("	calloc error: visit << ft_bfs_all\n");
		return ;
	}
	if (!(queue = (t_queue *)calloc(1, sizeof(t_queue))))
	{
		printf("	calloc error: queue << ft_bfs_all\n");
		free(visit);
		visit = NULL;
		return ;
	}
	i = -1;
	while (++i < graph->used_vertex)
	{
		if (!visit[i])
		{
			printf("	BFS: ");
			ft_bfs(graph, i, visit, queue);
			printf("\n");
		}
	}
	free(visit);
	visit = NULL;
}

void	ft_bfs(t_graph *graph, int index, int *visit, t_queue *queue)
{
	int		i;
	int		vertex;

	if (!graph || index > graph->used_vertex || index < 0 || !visit || !queue)
		return ;
	ft_enqueue(queue, index);
	visit[index] = 1;
	while (queue->count)
	{
		if ((vertex = ft_dequeue(queue)) < 0)
			return ;
		printf("%d ", vertex);
		i = -1;
		while (++i < graph->used_vertex)
		{
			if (!visit[i] && graph->adj_graph[vertex][i] == 1)
			{
				ft_enqueue(queue, i);
				visit[i] = 1;
			}
		}
	}
}

t_node	*ft_create_node(int index)
{
	t_node	*ret;

	if (!(ret = (t_node *)malloc(sizeof(t_node))))
	{
		printf("	malloc error: ft_create_node\n");
		return (ret);
	}
	ret->vertex = index;
	ret->next = NULL;
	return (ret);
}

void	ft_enqueue(t_queue *queue, int index)
{
	t_node	*node;

	if (!queue)
		return ;
	if (!(node = ft_create_node(index)))
	{
		printf("	alloc error: ft_create_node << ft_enqueue\n");
		return ;
	}
	if (!queue->count)
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

int		ft_dequeue(t_queue *queue)
{
	t_node	*ret;
	int		val;

	if (!queue || !queue->count)
		return (-1);
	ret = queue->front;
	queue->front = ret->next;
	queue->count -= 1;
	val = ret->vertex;
	free(ret);
	ret = NULL;
	return (val);
}