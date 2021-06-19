#ifndef FT_AVL_H
# define FT_AVL_H

# define PRE_ORDER	1
# define IN_ORDER	2
# define POST_ORDER	3
# define LEVEL		4

# define NORMAL		0
# define ABNORMAL	-1

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct	s_tree
{
	int			data;
	struct s_tree	*parent;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct	s_node
{
	struct s_node	*next;
	struct s_tree	*tree_node;
}				t_node;

typedef struct	s_queue
{
	int				count;
	struct s_node	*front;
	struct s_node	*back;
}				t_queue;

typedef struct	s_retNode
{
	struct s_tree	*child;
	struct s_tree	*ret_bal;
}				t_retNode;

// ft_create_tree_node.c
t_tree		*ft_create_tree_node(int data);

// ft_insert_tree_node.c
void		ft_insert_tree_node(t_tree **og_root, t_tree **root, t_tree *node, t_tree *parent, int *count);

// ft_print_utils.c
void		ft_println(int count);

// ft_queue.c
t_queue		*ft_create_queue(void);
t_node		*ft_create_s_node(t_tree *node);
void		ft_enqueue(t_queue *queue, t_tree *node);
t_node		*ft_dequeue(t_queue *queue);

// ft_search_tree_mode.c
void		ft_search_tree_mode(t_tree *root);
t_tree		*ft_search_tree_node(t_tree *root, int data);

// ft_traversal_tree_mode.c
void		ft_traversal_tree_mode(t_tree *root, int count);
void		ft_basic_trav_tree(t_tree *root, int order);
void		ft_level_trav_tree(t_tree *root);

// ft_delete_tree_node_mode.c
void		ft_delete_tree_node_mode(t_tree **og_root, int *count);
t_retNode	*ft_delete_tree_node(t_tree **og_root, t_tree *root, int data, t_tree *parent, int *count);
t_tree		*ft_max_val_in_left(t_tree *root);
t_retNode	*ft_create_ret_node(void);

// ft_remove_tree_mode.c
t_tree		*ft_remove_tree(t_tree *root, int *count);
void		ft_remove_tree_mode(t_tree **og_root, int *count);

// ft_insertion_balancing_mode.c
void		ft_insertion_balancing_mode(t_tree **og_root, t_tree *node);
int			ft_get_height_diff(t_tree *center);
int			ft_get_height(t_tree *root);

// ft_rotate.c
t_tree		*ft_rotate_ll(t_tree *x);
t_tree		*ft_rotate_lr(t_tree *x);
t_tree		*ft_rotate_rr(t_tree *x);
t_tree		*ft_rotate_rl(t_tree *x);

// ft_delete_balancing_mode.c
void	ft_deletion_balancing_mode(t_tree **og_root, t_retNode *ret_node);

#endif