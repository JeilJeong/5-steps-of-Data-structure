#include "../includes/ft_heap.h"

void	ft_println(int size)
{
	while (size--)
		printf("\n");
}

void	ft_print_heap(int *heap, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		printf("%d ", heap[i]);
}