#include "../includes/ft_heap.h"

int		*ft_heap_sort(int *heap, int size)
{
	int		*ret;
	int		*temp_heap;
	int		i;

	if (!heap)
		return (NULL);
	if (!(ret = (int *)malloc(sizeof(int) * size)))
	{
		printf("malloc error: ft_heap_sort\n");
		return (NULL);
	}
	temp_heap = ft_create_heap(size);
	ft_memcpy(temp_heap, heap, size);
	i = -1;
	while (++i < size)
	{
		ret[i] = ft_find_max_heap(temp_heap);
		printf("ret[%d] = %d\n", i, ret[i]);
		ft_print_heap(temp_heap, size);
		temp_heap = ft_delete_max_heap(temp_heap, size);
		size--;
	}
	return (ret);
}