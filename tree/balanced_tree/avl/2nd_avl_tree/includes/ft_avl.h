#ifndef FT_AVL_H
# define FT_AVL_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define NORMAL		0
# define ABNORMAL	-1

# define PRE_ORDER	1
# define IN_ORDER	2
# define POST_ORDER	3
# define LEVEL		4

typedef struct	s_tree
{
	int				data;
	int				height;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*parent;
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

// ft_crud_avl.c
t_tree	*ft_create_node(int data);
t_tree	*ft_insert_node(t_tree **root, t_tree *node, int height, t_tree *parent);

// ft_print_utils.c
void	ft_println(int i);
void	ft_print_tree(t_tree *root, int count);
void	ft_tree_traversal(t_tree *root, int order);
void	ft_level_traversal(t_tree *root);

// ft_queue.c
t_queue	*ft_create_queue(void);
t_node	*ft_create_queue_node(t_tree *tree_node);
void	ft_enqueue(t_queue *queue, t_tree *tree_node);
t_node	*ft_dequeue(t_queue *queue);
#endif