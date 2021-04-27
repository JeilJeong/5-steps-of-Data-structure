#include "../includes/ft_heap.h"

int		ft_max_index(int *heap, int index, int left, int right)
{
	int		ret;

	ret = heap[index] > heap[left] ? index : left;
	ret = heap[ret] > heap[right] ? ret : right;
	return (ret);
}

int		ft_min_index(int *heap, int index, int parent)
{
	int		ret;

	ret = heap[index] < heap[parent] ? index : parent;
	return (ret);
}

void	ft_heapify_up(int *heap, int index)
{
	int		parent;
	int		min_index;
	int		tmp;

	if (!heap)
		return ;
	while (index != 0)
	{
		parent = index / 2;
		if (index % 2 == 0)
			parent -= 1;
		min_index = ft_min_index(heap, index, parent);
		if (min_index != index)
		{
			tmp = heap[index];
			heap[index] = heap[min_index];
			heap[min_index] = tmp;
			index = min_index;
		}
		else
			return ;
	}
}

void	ft_heapify_down(int *heap, int size, int index)
{
	int		left;
	int		right;
	int		flag;
	int		index_size;
	int		min_index;
	int		tmp;

	if (!heap)
		return ;
	flag = 0;
	index_size = size - 1;
	while (!flag)
	{
		left = 2 * index + 1;
		right = 2 * index + 2;
		if (left > index_size)
		{
			flag = 1;
			continue;
		}
		else if (right > index_size)
			min_index = ft_max_index(heap, index, left, index);
		else
			min_index = ft_max_index(heap, index, left, right);
		if (min_index != index)
		{
			tmp = heap[index];
			heap[index] = heap[min_index];
			heap[min_index] = tmp;
			index = min_index;
		}
		else
			return ;
	}
}

int		ft_find_max_heap(int *heap)
{
	if (!heap)
		return (-1);
	return (heap[0]);
}