#ifndef FT_TREE_H
# define FT_TREE_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define PRE_ORDER 1
# define IN_ORDER 2
# define POST_ORDER 3

typedef struct	s_tree
{
	int				data;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

// ft_tree.c
t_tree	*ft_create_node(int data);
int		ft_insert_node(t_tree **root, t_tree *node);
void	ft_print_tree(t_tree *root, int order);

#endif