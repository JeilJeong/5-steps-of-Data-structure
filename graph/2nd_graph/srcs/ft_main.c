#include "../includes/ft_graph.h"

int		main(void)
{
	int		i;
	int		input;
	int		edge_size;
	int		vertex_size;
	int		vertex;
	t_graph	*graph;

	while (1)
	{
		graph = NULL;
		printf("	==== Menu ====\n");
		printf("	[1] Make Graph\n");
		printf("	[2] Exit\n");
		printf("	>>> ");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("	Vertex Size: ");
			scanf("%d", &vertex_size);
			if (vertex_size < 1 || vertex_size > 10)
			{
				printf("	Vertex size can be from 0 to 10\n");
				break;
			}
			if (!(graph = ft_create_graph(vertex_size)))
			{
				printf("	alloc error: ft_create_graph << ft_main.c\n");
				break;
			}
			ft_init_graph(graph, vertex_size);
			srand(time(NULL));
			i = -1;
			while (++i < vertex_size)
			{
				edge_size = rand() % vertex_size;
				while (edge_size--)
				{
					vertex = rand() % vertex_size;
					if (ft_find_vertex(graph, i, vertex) < 0)
						return (ABNORMAL);
					else if (!ft_find_vertex(graph, i, vertex))
					{
						ft_insert_node(graph, i, ft_create_node(vertex, 1));
						ft_insert_node(graph, vertex, ft_create_node(i, 1));
						graph->edge_cnt++;
					}
				}
			}
			ft_print_all_vertex(graph);
			graph = ft_delete_graph(graph);
		}
		else if (input == 2)
		{
			graph = ft_delete_graph(graph);
			break;
		}
	}
}