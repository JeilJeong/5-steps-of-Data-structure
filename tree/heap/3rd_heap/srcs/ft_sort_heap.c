#include "../includes/ft_heap.h"

int		*ft_heap_sort(int *heap, int size)
{
	int		*ret;
	int		*temp_heap;
	int		i;
	int		len;

	if (!heap)
		return (NULL);
	if (!(ret = (int *)malloc(sizeof(int) * size)))
	{
		printf("malloc error: ft_heap_sort\n");
		return (NULL);
	}
	temp_heap = ft_create_heap(size);
	ft_memcpy(temp_heap, heap, size * sizeof(int));
	i = -1;
	len = size;
	while (++i < len)
	{
		ret[i] = ft_find_max_heap(temp_heap);
		temp_heap = ft_delete_max_heap(temp_heap, size);
		size--;
	}
	free(temp_heap);
	return (ret);
}

int		*ft_heap_sort_print_version(int *heap, int size)
{
	int		i;
	int		len;

	if (!heap)
		return (NULL);
	i = -1;
	len = size;
	while (++i < len)
	{
		printf("%d ", ft_find_max_heap(heap));
		heap = ft_delete_max_heap(heap, size);
		size--;
	}
	printf("\n");
	return (heap);
}