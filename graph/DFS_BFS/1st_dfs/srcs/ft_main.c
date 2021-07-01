#include "../includes/ft_graph.h"

int		main(void)
{
	int		i;
	int		input;
	int		size;
	int		edge_size;
	int		vertex;
	t_graph	*graph;

	while (1)
	{
		printf("	==== Menu ====\n");
		printf("	[1] Make Graph\n");
		printf("	[2] Exit\n");
		printf("	>>> ");
		scanf("%d", &input);
		if (input == 1)
		{
			ft_println(1);
			printf("	Size: ");
			scanf("%d", &size);
			if (!(graph = ft_create_graph(size)))
			{
				printf("	alloc error: ft_create_graph << main\n");
				continue;
			}
			srand(time(NULL));
			i = -1;
			while (++i < size)
			{
				edge_size = rand() % size;
				while (edge_size--)
				{
					vertex = rand() % size;
					if (!graph->adj_graph[i][vertex])
					{
						graph->adj_graph[i][vertex] = 1;
						graph->adj_graph[vertex][i] = 1;
						graph->edge_cnt += 1;
					}
				}
			}
			while (1)
			{
				ft_println(1);
				printf("	==== Sub Menu ====\n");
				printf("	[1] Print Vertex\n");
				printf("	[2] DFS\n");
				printf("	[3] BFS\n");
				printf("	[4] Delete Graph\n");
				printf("	[5] Back to Main\n");
				printf("	>>> ");
				scanf("%d", &input);
				if (input == 1)
					ft_print_all_vertex(graph);
				else if (input == 2)
					ft_dfs_all(graph);
				// else if (input == 3)
					// ft_bfs_all(graph);
				else if (input == 4)
					graph = ft_delete_graph(graph);
				else if (input == 5)
					break;
			}
		}
		else if (input == 2)
		{
			graph = ft_delete_graph(graph);
			break;
		}
		ft_println(1);
	}
}