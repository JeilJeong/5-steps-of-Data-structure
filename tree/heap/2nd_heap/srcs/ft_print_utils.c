#include "../includes/ft_heap.h"

void	ft_print_heap(int *heap, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		printf("%d ", heap[i]);
	ft_println(1);
}

void	ft_println(int size)
{
	while (size > 0)
	{
		printf("\n");
		size--;
	}
}