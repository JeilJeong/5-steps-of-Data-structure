#include "../includes/ft_list.h"

extern int	count;

t_list	*ft_init(void)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
	{
		ft_sub_error(__FILE__, __func__, __LINE__, "malloc error");
		return (NULL);
	}
	ret->data = 0;
	ret->next = NULL;
	return (ret);
}

t_list	*ft_create_node(int data)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
	{
		ft_sub_error(__FILE__, __func__, __LINE__, "malloc error");
		return (NULL);
	}
	ret->data = data;
	ret->next = NULL;
	return (ret);
}

int		ft_insert_node(t_list *head, t_list *node, int pos)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = head;
	if (pos < 0 || pos > count)
		return (0);
	while (i < pos)
	{
		cur = cur->next;
		i++;
	}
	node->next = cur->next;
	cur->next = node;
	return (1);
}

void	ft_print_list(t_list *head)
{
	int		i;
	t_list	*cur;

	i = 0;
	cur = head->next;
	while (cur)
	{
		printf("list[%d] = %d\n", i, cur->data);
		cur = cur->next;
		i++;
	}
}

int		ft_delete_node(t_list *head, int pos)
{
	int		i;
	t_list	*cur;
	t_list	*prev;

	i = 0;
	prev = head;
	cur = head->next;
	if (pos < 0 || pos >= count)
		return (0);
	while (i < pos)
	{
		prev = cur;
		cur = cur->next;
		i++;
	}
	prev->next = cur->next;
	free(cur);
	return (1);
}

void	ft_bubble_sort_list(t_list *head)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;
	t_list	*temp;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = count - 1;
	while (i < len)
	{
		prev = head;
		cur = head->next;
		next = cur->next;
		j = 0;
		while (j < len - i)
		{
			if (cur->data > next->data)
			{
				// swap nodes
				prev->next = next;
				cur->next = next->next;
				next->next = cur;
				// rearrange variables after swapping nodes
				temp = next;
				next = cur;
				cur = temp;
			}
			prev = cur;
			cur = cur->next;
			next = cur->next;
			j++;
		}
		i++;
	}
}
