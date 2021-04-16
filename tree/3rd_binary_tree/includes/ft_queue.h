#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_queue
{
	struct s_node	*front;
	struct s_node	*back;
	int				count; 
}				t_queue;

typedef	struct	s_node
{
	struct s_node	*next;
	struct t_tree	*tree_node;
}				t_node;

t_queue	*ft_create_queue(void);
t_node	*ft_create_tnode(t_tree	*tree_node);
void	ft_enqueue(t_queue *queue, t_tree *tree_node);
t_node	*ft_dequeue(t_queue *queue);

#endif