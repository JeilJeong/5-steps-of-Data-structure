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

// ft_insert_tree_node.c

// ft_print_utils.c

// ft_queue.c

// ft_search_tree_mode.c

// ft_traversal_tree_mode.c

#endif