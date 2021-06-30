#include "../includes/ft_graph.h"

void	ft_println(int size)
{
	while (size--)
		printf("\n");
}

void	ft_print_all_vertex(t_graph *graph)
{
	int		i;
	int		j;

	if (!graph)
		return ;
	printf("	Used vertex: %d\n", graph->used_vertex);
	printf("	Edge count: %d\n", graph->edge_cnt);
	i = -1;
	while (++i < graph->used_vertex)
	{
		printf("	Vertex[%d]: ", i);
		j = -1;
		while (++j < graph->used_vertex)
		{
			if (graph->adj_graph[i][j])
				printf("%d ", j);
		}
		ft_println(1);
	}
}