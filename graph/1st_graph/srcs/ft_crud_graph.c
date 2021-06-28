#include "../includes/ft_graph.h"

t_graph	*ft_create_graph(void)
{
	int		i;
	t_graph	*ret;

	if (!(ret = (t_graph *)malloc(sizeof(t_graph))))
	{
		printf("	malloc error: ft_create_graph\n");
		return (ret);
	}
	i = -1;
	while (++i < MAX_VERTEX)
		(ret->graph)[i] = NULL;
	ret->vertex_cnt = 0;
	ret->edge_cnt = 0;
	return (ret);
}

void	ft_init_graph(t_graph *graph, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		graph->graph[i] = ft_create_node(i, 1);
		graph->vertex_cnt += 1;
	}
}