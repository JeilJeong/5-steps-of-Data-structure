#ifndef FT_AVL_H
# define FT_AVL_H

# define NORMAL		0
# define ABNORMAL	-1

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct	s_tree
{
	int				data;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*parent;
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

// ft_crud_tree.c
t_tree	*ft_create_tree_node(int data);
void	ft_insert_tree_node(t_tree **og_root, t_tree **root, t_tree *node, t_tree *parent, int *count);
t_tree	*ft_remove_tree_mode(t_tree **og_root, t_tree *root, int *count);
t_tree *ft_remove_tree(t_tree *root, int *count);

// ft_print_utils.c
void	ft_println(int size);

// ft_search_tree_node_mode.c
void	ft_search_node_mode(t_tree *root);
t_tree	*ft_search_tree_node(t_tree *root, int data);

// ft_traversal_mode.c
void	ft_traversal_node_mode(t_tree *root);
void	ft_traversal_order(t_tree *root, int order);

// ft_traversal_level_mode.c
void	ft_traversal_level_mode(t_tree *root);
t_queue	*ft_create_queue(void);
void	ft_enqueue(t_queue *queue, t_tree *tree_node);
t_node *ft_dequeue(t_queue *queue);
t_node *ft_create_queue_node(t_tree *tree_node);

// ft_delete_tree_node_mode.c
void	ft_delete_node_mode(t_tree **og_root, t_tree *root, t_tree *parent, int *count);
t_tree	*ft_delete_tree_node(t_tree **og_root, t_tree *root, t_tree *parent, int *count, int data);
t_tree *ft_find_max_node_in_left(t_tree *root);

// ft_balancing_tree.c
void	ft_balancing_tree(t_tree **og_root, t_tree *node);
int		ft_compare_height(t_tree *root);
int		ft_get_height(t_tree *root);

// ft_rotate_tree.c
t_tree	*ft_rotate_ll(t_tree *x);
t_tree	*ft_rotate_lr(t_tree *x);
t_tree	*ft_rotate_rr(t_tree *x);
t_tree	*ft_rotate_rl(t_tree *x);

#endif