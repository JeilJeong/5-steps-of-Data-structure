#include "../includes/ft_heap.h"

int		main(void)
{
	int		*heap;
	int		size;
	int		range;

	printf("Type heap size: ");
	scanf("%d", &size);

	printf("Type heap range: ");
	scanf("%d", &range);

	// ft_create_heap
	if (!(heap = ft_create_heap(size)))
	{
		printf("alloc error: main");
		return (ABNORMAL);
	}
	// ft_insert_heap

	// ft_find_max_heap

	// ft_delete_max_heap
}