#ifndef FT_AVL_H
# define FT_AVL_H

# define ABNORMAL	-1
# define NORMAL		0

# define PRE_ORDER	1
# define IN_ORDER	2
# define POST_ORDER	3
# define LEVEL		4

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

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
int		ft_insert_node(t_tree **root, t_tree *node, t_tree *parent, int height);
void	ft_search_node(t_tree *root, int input);
t_tree	*ft_delete_node(t_tree *root, int input);
t_tree	*ft_delete_tree(t_tree *root);

// ft_print_utils.c
void	ft_println(int size);
int		ft_print_tree(t_tree *root, int order);
int		ft_print_level(t_tree *root);
void	ft_print_delete_case(int input);

// ft_queue.c
t_queue	*ft_create_queue(void);
int		ft_enqueue(t_queue *queue, t_tree *tree_node);
t_node	*ft_create_queue_node(t_tree *tree_node);
t_node	*ft_dequeue(t_queue *queue);

// ft_avl_utils.c
t_tree	*ft_find_max(t_tree *root);
void	ft_resolve_height(t_tree *root);

#endif