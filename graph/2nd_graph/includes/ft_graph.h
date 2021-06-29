#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# define ABNORMAL	-1
# define NORMAL		0
# define MAX_SIZE	10

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct	s_graph
{
	int				vertex_cnt;
	int				edge_cnt;
	struct s_node	*arr[MAX_SIZE];
}				t_graph;

typedef struct	s_node
{
	int				vertex;
	int				weight;
	struct s_node	*next;
}				t_node;

// ft_crud_graph.c
t_graph	*ft_create_graph(int vertex_size);
t_graph	*ft_init_graph(t_graph *graph, int vertex_size);
int		ft_find_vertex(t_graph *graph, int index, int vertex);
t_graph	*ft_delete_graph(t_graph *graph);
t_node	*ft_delete_list(t_node *list);

// ft_crud_node.c
t_node	*ft_create_node(int vertex, int weight);
void	ft_insert_node(t_graph *graph, int index, t_node *node);
void	ft_print_all_vertex(t_graph *graph);

// ft_print_utils.c

#endif