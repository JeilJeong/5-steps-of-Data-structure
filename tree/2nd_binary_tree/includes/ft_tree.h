#ifndef FT_TREE_H
# define FT_TREE_H

# define PRE_ORDER	1
# define IN_ORDER	2
# define POST_ORDER	3

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_tree
{
	int				data;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

// ft_tree.c
t_tree	*ft_new_node(int data);
int		ft_insert_node(t_tree **p_root, int data);
void	ft_print_node(t_tree *root, int	order);
void	ft_search_node(t_tree *root, int search);
t_tree	*ft_delete_node(t_tree *root, int data);
t_tree	*ft_max_node(t_tree *root);

#endif