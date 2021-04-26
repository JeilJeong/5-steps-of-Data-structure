#include "../includes/ft_heap.h"

int		*ft_create_heap(int size)
{
	int		*ret;

	if (!(ret = (int *)malloc(sizeof(int) * size)))
	{
		printf("malloc error: ft_create_heap");
		return (NULL);
	}
	ft_memset((void *)ret, 0, (unsigned long)(sizeof(int) * size));
	return (ret);
}