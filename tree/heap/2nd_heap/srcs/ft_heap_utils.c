#include "../includes/ft_heap.h"

int		ft_max_index(int *heap, int index, int left, int right)
{
	int		ret;

	ret = heap[left] > heap[right] ? left : right;
	ret = heap[ret] > heap[index] ? ret : index;
	return (ret);
}

void	ft_make_heap(int *heap, int size)
{
	int		i;

	i = size;
	if (!heap)
		return ;
	while (--i >= 0)
		ft_heapify_down(heap, i, size);
}

void	ft_heapify_up(int *heap, int index)
{
	int		parent;
	int		tmp;
	int		flag;

	flag = 0;
	if (!heap)
		return ;
	else
	{
		while (!flag)
		{
			parent = index / 2;
			if (index % 2 == 0)
				parent -= 1;
			if (parent < 0)
			{
				flag = 1;
				continue;
			}
			if (heap[index] > heap[parent])
			{
				tmp = heap[index];
				heap[index] = heap[parent];
				heap[parent] = tmp;
				index = parent;
			}
		}
	}
}

void	ft_heapify_down(int *heap, int index, int size)
{
	int		flag;
	int		left;
	int		right;
	int		len;
	int		max_index;
	int		tmp;

	flag = 0;
	len = size -1;
	if (!heap)
		return ;
	while (!flag)
	{
		left = 2 * index + 1;
		right = 2 * index + 2;

		if (left > len || right > len)
		{
			flag = 1;
			continue;
		}
		max_index = ft_max_index(heap, index, left, right);
		if (max_index == index)
			return ;
		else
		{
			tmp = heap[index];
			heap[index] = heap[max_index];
			heap[max_index] = tmp;
			index = max_index;
		}
	}
}

int		ft_find_max_heap(int *heap)
{
	if (!heap)
		return (-1);
	return (heap[0]);
}