#include "../includes/ft_graph.h"

t_node	*ft_create_node(int vertex, int weight)
{
	t_node	*ret;

	if (!(ret = (t_node *)malloc(sizeof(t_node))))
	{
		printf("	malloc error: ft_create_node\n");
		return (NULL);
	}
	ret->vertex = vertex;
	ret->weight = weight;
	ret->next = NULL;
	return (ret);
}

void	ft_insert_node(t_graph *graph, int index, t_node *node)
{
	t_node	*cur;

	if (!graph || !node)
		return	;
	cur = graph->graph[index];
	while (cur->next)
		cur = cur->next;
	cur->next = node;
}

int		ft_find_node(t_graph *graph, int index, int vertex)
{
	t_node	*cur;

	if (!graph)
		return (0);
	cur = graph->graph[index];
	while (cur)
	{
		if (cur->vertex == vertex)
			return (1);
		cur = cur->next;
	}
	return (0);
}