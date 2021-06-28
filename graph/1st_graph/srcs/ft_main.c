#include "../includes/ft_graph.h"

int		main(void)
{
	int		size;
	int		input;
	int		i;
	int		rand_vertex;
	int		rand_edge;
	t_graph	*graph;

	while (1)
	{
		printf("	--- MAIN ---\n");
		printf("	[1] Make Graph\n");
		printf("	[2] Exit\n");
		printf("	>>> ");
		scanf("%d", &input);

		if (input == 1)
		{
			while (1)
			{
				ft_println(1);
				printf("	--- Type Size: MAX 20 ---\n");
				printf("	>>> ");
				scanf("%d", &size);
				if (size > 20)
				{
					printf("	Size can be allocated up to 20\n");
					continue;
				}
				if (!(graph = ft_create_graph()))
				{
					printf("	alloc error: ft_create_graph <<< main\n");
					return (1);
				}
				// insert self vertex node to each array space
				ft_init_graph(graph, size);
				i = -1;
				srand(time(NULL));
				while (++i < size)
				{
					rand_edge = rand() % size;
					while (rand_edge--)
					{
						rand_vertex = rand() % size;
						if (!ft_find_node(graph, i, rand_vertex))
						{
							// random 노드 삽입 후 반대 노드도 삽입 필요 -> 무방향 그래프이기 때문
							ft_insert_node(graph, i, ft_create_node(rand_vertex, 1));
							ft_insert_node(graph, rand_vertex, ft_create_node(i, 1));
							graph->edge_cnt += 1;
						}
					}
				}
				// print graph by dfs
				printf("	DFS: ");
				ft_print_by_dfs(graph, size);
				ft_println(2);
				// printf("	BFS: ");
				// ft_print_by_bfs(graph, size);
				// ft_println(1);
			}
		}
		else if (input == 2)
			break;
	}
}