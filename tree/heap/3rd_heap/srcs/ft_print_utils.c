#include "../includes/ft_heap.h"

void	ft_print_heap(int *heap, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		printf("%d ", heap[i]);
		i++;
	}
	printf("\n");
}