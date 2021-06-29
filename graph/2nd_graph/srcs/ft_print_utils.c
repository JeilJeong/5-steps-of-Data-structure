#include "../includes/ft_graph.h"

void	ft_print_all_vertex(t_graph *graph)
{
	int		i;
	t_node	*cur;

	if (!graph)
		return ;
	printf("	Vertex_cnt: %d\n", graph->vertex_cnt);
	printf("	Edge_cnt: %d\n", graph->edge_cnt);
	i = -1;
	while (++i < graph->vertex_cnt)
	{
		printf("	Vertex[%d]: ", i);
		cur = graph->arr[i];
		while (cur)
		{
			printf("%d ", cur->vertex);
			cur = cur->next;
		}
		printf("\n");
	}
}