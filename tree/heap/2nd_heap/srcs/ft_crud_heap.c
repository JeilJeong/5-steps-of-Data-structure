#include "../includes/ft_heap.h"

int		*ft_create_heap(int size)
{
	int		*ret;

	if (!(ret = (int *)malloc(sizeof(int) * size)))
	{
		printf("malloc error: ft_create_heap\n");
		return (NULL);
	}
	return (ret);
}

void	ft_init_heap(int *heap, int size, int range)
{
	int		i;

	i = 0;
	srand((unsigned int)time(NULL));
	while (i < size)
	{
		heap[i] = rand() % range;
		i++;
	}
}

int		*ft_delete_max_heap(int *heap, int size)
{
	int		tmp;
	int		*re_heap;
	int		re_size;

	if (!heap)
		return (0);
	else
	{
		re_size = size - 1;
		tmp = heap[0];
		heap[0] = heap[size - 1];
		heap[size - 1] = tmp;
		re_heap = ft_rearrange_heap(heap, re_size);
		ft_heapify_down(re_heap, 0, re_size);
	}
	free(heap);
	return (re_heap);
}

int		*ft_rearrange_heap(int *heap, int size)
{
	int		*ret;
	int		i;

	if (!heap)
		return (NULL);
	else
	{
		if (!(ret = (int *)malloc(sizeof(int) * size)))
		{
			printf("malloc error: ft_rearrange_heap\n");
			return (NULL);
		}
		i = -1;
		while (++i < size)
			ret[i] = heap[i];
	}
	return (ret);
}

int		*ft_insert_heap(int *heap, int size, int input)
{
	int		*re_heap;
	int		re_size;
	int		i;

	if (!heap)
		return (NULL);
	else
	{
		re_size = size + 1;
		if (!(re_heap = (int *)malloc(sizeof(int) * re_size)))
		{
			printf("malloc error: ft_insert_heap\n");
			return (heap);
		}
		i = -1;
		while (++i < size)
			re_heap[i] = heap[i];
		re_heap[i] = input;
		ft_heapify_up(re_heap, i);
	}
	return (re_heap);
}
