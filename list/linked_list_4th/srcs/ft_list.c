#include "../includes/ft_list.h"

extern int	count;

t_list		*ft_create_list(void)
{
	t_list	*ret;

	if ((ret = (t_list *)malloc(sizeof(t_list))) == NULL)
	{
		printf("malloc error: ft_create_list");
		return (NULL);
	}
	ret->data = 0;
	ret->next = NULL;
	return (ret);
}

int			ft_insert_node(t_list *head, int pos, int data)
{
	t_list	*node;
	t_list	*prev;
	int		i;

	if ((node = (t_list *)malloc(sizeof(t_list))) == NULL)
	{
		printf("malloc error: ft_insert_node");
		return (0);
	}
	node->data = data;
	node->next = NULL;
	if (pos < 0 || pos > count)
		return (0);
	i = 0;
	prev = head;
	while (i < pos)
	{
		prev = prev->next;
		i++;
	}
	node->next = prev->next;
	prev->next = node;
	return (1);
}

void	ft_print_list(t_list *head)
{
	t_list *cur;
	int		i;

	cur = head->next;
	i = 0;
	while (cur)
	{
		printf("list[%d] = %d\n", i, cur->data);
		cur = cur->next;
		i++;
	}
}