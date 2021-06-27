#include "../includes/ft_heap.h"

int		*ft_make_heap(int *heap, int size)
{
	int		index;

	index = size;
	while (--index >= 0)
		ft_heapify_down(heap, size, index);
	return (heap);
}

void	ft_heapify_down(int *heap, int range, int index)
{
	int		left;
	int		right;
	int		max_index;
	int		flag;
	int		tmp;

	flag = 0;
	while (!flag)
	{
		left = 2 * index + 1;
		right = 2 * index + 2;
		if (left >= range)
		{
			flag = 1;
			continue;
		}
		else if (right >= range)
			max_index = heap[index] > heap[left] ? index : left;
		else
			max_index = heap[left] > heap[right] ? left : right;
		if (heap[max_index] > heap[index])
		{
			tmp = heap[index];
			heap[index] = heap[max_index];
			heap[max_index] = tmp;
			index = max_index;
		}
		else
			return ;
	}
}