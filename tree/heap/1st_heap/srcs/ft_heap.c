#include "../includes/ft_heap.h"

int		*ft_create_heap(int size)
{
	int		*heap;

	if (!(heap = (int *)malloc(sizeof(int) * size)))
	{
		printf("malloc error: in main\n");
		return (NULL);
	}
	return (heap);
}

void	ft_make_heap(int *heap, int size)
{
	int	i;

	i = size;
	if (!heap)
		return ;
	while (i >= 0)
	{
		ft_heapify_down(heap, i, size);
		i--;
	}
}

void	ft_heapify_down(int *heap, int index, int size)
{
	int		left;
	int		right;
	int		max_index;
	int		leaf_flag;
	int		tmp;

	leaf_flag = 0;
	left = -1;
	right = -1;
	tmp = 0;
	if (!heap)
		return ;
	while (!leaf_flag)
	{
		left = 2 * index + 1;
		right = 2 * index + 2;

		if (left > size || right > size)
		{
			leaf_flag = 1;
			continue;
		}
		if ((max_index = ft_max_index(heap, index, left, right)) < 0)
			return ;
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

int		ft_max_index(int *heap, int index, int left, int right)
{
	int		max_index;

	max_index = -1;
	if (!heap)
		return (-1);
	max_index = heap[left] > heap[right] ? left : right;
	max_index = heap[index] > heap[max_index] ? index : max_index;
	return (max_index);
}

int		ft_max_heap(int	*heap)
{
	return (heap[0]);
}

int		*ft_delete_max_heap(int *heap, int size)
{
	int		tmp;
	int		*re_heap;

	tmp = heap[0];
	heap[0] = heap[size - 1];
	heap[size - 1] = tmp;
	re_heap = ft_rearrange_heap(heap, size - 1);
	ft_heapify_down(re_heap, 0, size - 1);
	return (re_heap);
}

int		*ft_rearrange_heap(int	*heap, int len)
{
	int		*ret;
	int		i;

	if (!(ret = (int *)malloc(sizeof(int) * len)))
	{
		printf("malloc error: ft_rearrange_heap\n");
		return (NULL);
	}
	i = -1;
	while (++i < len)
		ret[i] = heap[i];
	return (ret);
}