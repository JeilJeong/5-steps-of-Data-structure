#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# define MAX_VERTEX	20

typedef struct	s_graph
{
	struct	s_node	*graph[MAX_VERTEX];
	int				vertex_cnt;
	int				edge_cnt;
}				t_graph;

typedef struct	s_node
{
	int				vertex;
	int				weight;
	struct s_node	*next;
}				t_node;

// ft_crud_graph.c
t_graph	*ft_create_graph(void);
void	ft_init_graph(t_graph *graph, int size);

// ft_crud_node.c
t_node	*ft_create_node(int vertex, int weight);
void	ft_insert_node(t_graph *graph, int index, t_node *node);
int		ft_find_node(t_graph *graph, int index, int vertex);

// ft_print_utils.c
void	ft_println(int size);
void	ft_print_by_dfs(t_graph *graph, int size);
void	ft_stack_push(int **head, t_node *node);
int		ft_stack_pop(int *stack, int **head);

#endif