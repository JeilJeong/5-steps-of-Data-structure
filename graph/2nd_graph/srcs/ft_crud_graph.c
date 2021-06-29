#include "../includes/ft_graph.h"

t_graph	*ft_create_graph(int vertex_size)
{
	int		i;
	t_graph	*ret;

	if (!(ret = (t_graph *)malloc(sizeof(t_graph))))
	{
		printf("	malloc error: ft_create_graph\n");
		return (NULL);
	}
	ret->vertex_cnt = vertex_size;
	ret->edge_cnt = 0;
	i = -1;
	while (++i < MAX_SIZE)
		ret->arr[i] = NULL;
	return (ret);
}

t_graph	*ft_init_graph(t_graph *graph, int vertex_size)
{
	int		i;

	if (!graph)
		return (NULL);
	i = -1;
	while (++i < vertex_size)
	{
		if (!(graph->arr[i] = ft_create_node(i, 1)))
		{
			printf("	alloc error: ft_create_node << ft_init_graph\n");
			continue;
		}
	}
	return (graph);
}

int		ft_find_vertex(t_graph *graph, int index, int vertex)
{
	t_node	*cur;

	if (!graph)
		return (-1);
	cur = graph->arr[index];
	while (cur)
	{
		if (cur->vertex == vertex)
			return (1);
		cur = cur->next;
	}
	return (0);
}

t_graph	*ft_delete_graph(t_graph *graph)
{
	int		i;

	if (!graph)
		return (NULL);
	i = -1;
	while (++i < graph->vertex_cnt)
		graph->arr[i] = ft_delete_list(graph->arr[i]);
	free(graph);
	graph = NULL;
	return (graph);
}

t_node	*ft_delete_list(t_node *list)
{
	if (!list)
		return (NULL);
	if (list->next)
		list->next = ft_delete_list(list->next);
	free(list);
	list = NULL;
	return (list);
}