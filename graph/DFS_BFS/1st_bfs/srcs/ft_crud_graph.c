#include "../includes/ft_graph.h"

t_graph *ft_create_graph(int size)
{
	t_graph	*graph;
	int		i;

	if (size < 1 || size > MAX_SIZE)
	{
		printf("	Size can be from 1 to %d\n", MAX_SIZE);
		return (NULL);
	}
	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
	{
		printf("	malloc error: graph << ft_create_graph\n");
		return (NULL);
	}
	graph->max_vertex = MAX_SIZE;
	graph->used_vertex = size;
	graph->edge_cnt = 0;
	if (!(graph->vertex = (int *)calloc(size, sizeof(int))))
	{
		printf("	calloc error: graph->vertex << ft_create_graph\n");
		free(graph);
		graph = NULL;
		return (NULL);
	}
	if (!(graph->adj_graph = (int **)calloc(size, sizeof(int *))))
	{
		printf("	calloc error: graph->adj_graph << ft_create_graph\n");
		free(graph->vertex);
		graph->vertex = NULL;
		free(graph);
		graph = NULL;
		return (NULL);
	}
	i = -1;
	while (++i < size)
	{
		if (!(graph->adj_graph[i] = (int *)calloc(size, sizeof(int))))
		{
			printf("	calloc error: graph->adj_graph[%d] << ft_create_graph\n", i);
			while (i--)
			{
				free(graph->adj_graph[i]);
				graph->adj_graph[i] = NULL;
			}
			free(graph->vertex);
			graph->vertex = NULL;
			free(graph);
			graph = NULL;
			return (NULL);
		}
	}
	i = -1;
	while (++i < size)
	{
		graph->vertex[i] = USED;
		graph->adj_graph[i][i] = 1;
	}
	return (graph);
}

t_graph	*ft_delete_graph(t_graph *graph)
{
	int		i;

	if (!graph)
		return (NULL);
	i = -1;
	while (++i < graph->used_vertex)
	{
		free(graph->adj_graph[i]);
		graph->adj_graph[i] = NULL;
	}
	free(graph->adj_graph);
	graph->adj_graph = NULL;
	free(graph->vertex);
	graph->vertex = NULL;
	free(graph);
	graph = NULL;
	return (graph);
}