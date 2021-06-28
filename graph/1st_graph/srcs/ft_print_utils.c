#include "../includes/ft_graph.h"

void	ft_println(int size)
{
	while (size--)
		printf("\n");
}

void	ft_print_by_dfs(t_graph *graph, int size)
{
	int		i;
	int		flag;
	int		index;
	int		visit[size];
	int		stack[size];
	int		**head;
	t_node	*cur;

	i = -1;
	if (!graph)
		return ;
	while (++i < size)
	{
		stack[i] = 0;
		visit[i] = 0;
	}
	flag = 0;
	head = &stack;
	index = 0;
	while (!flag)
	{
		cur = graph->graph[index];
		while (cur)
		{
			if (!visit[cur->vertex])
				ft_stack_push(head, cur);
			cur = cur->next;
		}
		if ((index = ft_stack_pop(stack, head) < 0))
		{
			flag = 1;
			continue;
		}
		visit[index] = 1;
		if (!visit[index])
			printf("%d ", index);
	}
}

void	ft_stack_push(int **head, t_node *node)
{
	if (!head || !node)
		return ;
	**head = node->vertex;
	*head++;
}

int		ft_stack_pop(int *stack, int **head)
{
	if (!stack || !head)
		return (-1);
	if (*head < stack)
		return (-1);
	*head--;
	return (**head);
}
