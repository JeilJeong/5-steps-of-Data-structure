#include "../includes/ft_heap.h"

int		*ft_create_heap(int size)
{
	int		*ret;

	if (!(ret = (int *)malloc(sizeof(int) * size)))
	{
		printf("malloc error: ft_create_heap\n");
		return (NULL);
	}
	ft_memset((void *)ret, 0, (unsigned long)(sizeof(int) * size));
	return (ret);
}

void	ft_init_heap(int *heap, int size, int range)
{
	int	i;

	i = -1;
	srand((unsigned int)time(NULL));
	while (++i < size)
		heap[i] = rand() % range + 1;
}

void	ft_make_heap(int *heap, int size)
{
	int	index;

	index = size - 1;
	while (index >= 0)
	{
		ft_heapify_down(heap, size, index);
		index--;
	}
}

int		*ft_insert_heap(int *heap, int size, int input)
{
	int		len;
	int		*ret;

	len = size + 1;
	if (!(ret = (int *)malloc(sizeof(int) * len)))
	{
		printf("malloc error: ft_insert_heap");
		return (NULL);
	}
	ft_memcpy((void *)ret, (void *)heap, (size_t)(size * sizeof(int)));
	ret[size] = input;
	ft_heapify_up(ret, size);
	free(heap);
	return (ret);
}

int		*ft_delete_max_heap(int *heap, int size)
{
	int		swap;
	int		*ret;
	int		i;
	int		len;

	if (!heap)
		return (NULL);
	//	heap[0] node value change
	//	last node에 대해 삭제 -> 새로운 heap 할당
	// 새 heap에 대해서 make heap 진행;
	len = size - 1;
	swap = heap[0];
	heap[0] = heap[size - 1];
	heap[size - 1] = swap;
	if (!(ret = ft_create_heap(len)))
	{
		printf("alloc error: ft_delete_max_heap\n");
		return (NULL);
	}
	i = -1;
	while (++i < len)
		ret[i] = heap[i];
	free(heap);
	ft_heapify_down(ret, len, 0);
	return (ret);
}