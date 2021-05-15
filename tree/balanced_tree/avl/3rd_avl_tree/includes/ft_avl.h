#ifndef FT_AVL_H
# define FT_AVL_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_tree
{
	int				data;
	int				height;
	struct s_tree	*parent;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct	s_queue
{
	int				count;
	struct s_node	*front;
	struct s_node	*back;
}				t_queue;

typedef struct	s_node
{
	struct s_node	*next;
	struct s_tree	*tree_node;
}				t_node;

# define ABNORAML	-1
# define NORMAL		0

# define PRE_ORDER	1
# define IN_ORDER	2
# define POST_ORDER	3
# define LEVEL_TRAV	4

// ft_create_tree_node.c
t_tree	*ft_create_tree_node(int data);

// ft_insert_tree_node.c
int		ft_insert_tree_node(t_tree **og_root, t_tree **root, t_tree *node, t_tree *parent, int height);

// ft_search_tree_node.c
void	ft_search_node_mode(t_tree *root);
void	ft_search_tree_node(t_tree *root, int input);

// ft_delete_tree_node.c

// ft_delete_tree.c

// ft_print_utils.c
void	ft_println(int size);
void	ft_print_tree_mode(t_tree *root, int count);
void	ft_print_node(t_tree *root, int order);
void	ft_level_trav(t_tree *root);

// ft_balance_insertion_mode.c
void	ft_balance_check_insertion_mode(t_tree **og_root, t_tree *root);
t_tree	*ft_rebalancing_insertion_mode(t_tree *x, t_tree *y, t_tree *z);
int		ft_xyz_sequence_case(t_tree *x, t_tree *y, t_tree *z);
int		ft_find_deep(t_tree *root);

// ft_rebalancing_utils.c
t_tree	*ft_rotate_rr(t_tree *x, t_tree *y, t_tree *z);
t_tree	*ft_rotate_ll(t_tree *x, t_tree *y, t_tree *z);
t_tree	*ft_rotate_lr(t_tree *x, t_tree *y, t_tree *z);
t_tree	*ft_rotate_rl(t_tree *x, t_tree *y, t_tree *z);
void	ft_resolve_height(t_tree *root, int height);

// ft_queue.c
t_queue	*ft_create_queue(void);
void	ft_enqueue(t_queue *queue, t_tree *tree_node);
t_node	*ft_dequeue(t_queue *queue);
t_node	*ft_create_node(t_tree *tree_node);

#endif