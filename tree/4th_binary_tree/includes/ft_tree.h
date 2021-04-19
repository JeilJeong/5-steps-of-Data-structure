#ifndef FT_TREE_H
# define FT_TREE_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_tree
{
	int				data;
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

// ft_crud_tree.c
t_tree	*ft_create_tree_node(const int data);
void	ft_insert_tree_node(t_tree **root, t_tree *tree_node, int *count);
t_tree	*ft_delete_tree_node(t_tree *root, int data, int *count);
t_tree	*ft_delete_tree(t_tree *root, int *count);

// ft_utils.c
void	ft_println(int count);

// ft_print_tree.c
void	ft_print_tree(t_tree *root);
void	ft_level_traversal(t_tree *root);

// ft_queue.c
t_queue	*ft_create_queue(void);
t_node	*ft_create_queue_node(t_tree *tree_node);
void	ft_enqueue(t_queue *queue, t_tree *tree_node);
t_node	*ft_dequeue(t_queue *queue);

// ft_search_tree.c
void	ft_search_tree_node(t_tree *root, int data, int level);
t_tree	*ft_search_max_node(t_tree *root);

#endif