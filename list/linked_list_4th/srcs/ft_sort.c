# include "../includes/ft_list.h"

extern int	count;

void		ft_bubble_sort(t_list *head)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = count - 1;
	while (i < len)
	{
		prev = head;
		cur = prev->next;
		next = cur->next;
		j = 0;
		while (j < len - i)
		{
			if (cur->data > next->data)
			{
				prev->next = next;
				cur->next = next->next;
				next->next = cur;
				cur = prev->next;
				next = cur->next;
			}
			prev = cur;
			cur = cur->next;
			next = cur->next;
			j++;
		}
		i++;
	}
}