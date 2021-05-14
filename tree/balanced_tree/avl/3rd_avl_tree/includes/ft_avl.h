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
# define LEVEL		4

// ft_insert_node.c

// ft_delete_node.c

// ft_delete_tree.c

// ft_print_utils.c


#endif