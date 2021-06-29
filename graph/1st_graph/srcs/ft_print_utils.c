#include "../includes/ft_graph.h"

void	ft_println(int size)
{
	while (size--)
		printf("\n");
}

void	ft_print_all(t_graph *graph, int size)
{
	int		i;
	t_node	*cur;

	i = -1;
	printf("	vertex_cnt: %d\n", graph->vertex_cnt);
	printf("	edge_cnt: %d\n", graph->edge_cnt);
	while (++i < size)
	{
		printf("	vertex[%d]: ", i);
		cur = graph->graph[i];
		while (cur)
		{
			printf("%d ", cur->vertex);
			cur = cur->next;
		}
		ft_println(1);
	}
}