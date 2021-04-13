#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct	s_list{
	int				data;
	struct s_list	*next;
}				t_list;

// ft_list.c
t_list		*ft_create_list(void);
int			ft_insert_node(t_list *head, int pos, int data);
void		ft_print_list(t_list *head);

// ft_sort.c
void		ft_bubble_sort(t_list *head);

#endif