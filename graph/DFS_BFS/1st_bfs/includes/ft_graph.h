#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# define NORMAL		0
# define ABNORMAL	-1
# define MAX_SIZE	20
# define USED		1
# define NOT_USED	0

typedef struct	s_graph
{
	int			max_vertex;
	int			used_vertex;
	int			edge_cnt;
	int			**adj_graph;
	int			*vertex;
}				t_graph;

typedef struct	s_queue
{
	int				count;
	struct s_node	*front;
	struct s_node	*back;
}				t_queue;

typedef struct	s_node
{
	int				vertex;
	struct s_node	*next;
}				t_node;

// ft_create_graph.c
t_graph *ft_create_graph(int size);
t_graph	*ft_delete_graph(t_graph *graph);

// ft_print_utils.c
void	ft_println(int size);
void	ft_print_all_vertex(t_graph *graph);

// ft_bfs.c
void	ft_bfs_all(t_graph *graph);
void	ft_bfs(t_graph *graph, int index, int *visit, t_queue *queue);
t_node	*ft_create_node(int index);
void	ft_enqueue(t_queue *queue, int index);
int		ft_dequeue(t_queue *queue);

#endif