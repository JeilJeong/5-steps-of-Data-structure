#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list {
	int				data;
	struct s_list	*next;
}				t_list;

// ft_error.c
void	ft_error_indent(int len);
void	ft_sub_error(char *file, const char *func, int line, char *msg);
void	ft_main_error(char *file, const char *func, int line, char *msg);

// ft_list.c
t_list	*ft_init(void);
t_list	*ft_create_node(int data);
int		ft_insert_node(t_list *head, t_list *node, int pos);
void	ft_print_list(t_list *head);
int		ft_delete_node(t_list *head, int pos);
void	ft_bubble_sort_list(t_list *head);

#endif
