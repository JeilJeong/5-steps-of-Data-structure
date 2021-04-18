#ifndef FT_TREE_H
# define FT_TREE_H

# define PRE_ORDER		1
# define IN_ORDER		2
# define POST_ORDER		3

# define DEL_TERMINAL	1
# define DEL_BOTH		2
# define DEL_LEFT		3
# define DEL_RIGHT		4

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_tree
{
	int				data;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct	s_queue
{
	struct s_node	*front;
	struct s_node	*back;
	int				count; 
}				t_queue;

typedef	struct	s_node
{
	struct s_node	*next;
	struct s_tree	*tree_node;
}				t_node;

// ft_queue.c
t_queue	*ft_create_queue(void);
t_node	*ft_create_tnode(t_tree	*tree_node);
void	ft_enqueue(t_queue *queue, t_tree *tree_node);
t_node	*ft_dequeue(t_queue *queue);

// ft_crud_tree.c
t_tree	*ft_create_node(int data);
int		ft_insert_node(t_tree **root, t_tree *node);
t_tree	*ft_delete_node(t_tree *root, int *count);
t_tree	*ft_delete_input(t_tree *root, int data, int *count);
t_tree	*ft_delete_tree(t_tree *root);

// ft_print_utils.c
void	ft_print_tree(t_tree *root, int order);
void	ft_println(int times);
void	ft_print_input(int data);
void	ft_print_count(int count);
void	ft_print_delete_case(int input);

// ft_search_tree.c
void	ft_search_node(t_tree *root);
void	ft_search_input(t_tree *root, int data);
t_tree	*ft_find_max_node(t_tree *root);

// ft_level_traversal.c
void	ft_level_traversal(t_tree *root);

#endif