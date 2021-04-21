#include "../includes/ft_heap.h"

int		main(void)
{
	int		*heap;
	int		size;
	int		range;
	int		input;

	// Type heap size
	printf("Type heap size: ");
	scanf("%d", &size);

	// ft_create_heap
	if (!(heap = ft_create_heap(size)))
	{
		printf("heap allocation error: main");
		return(-1);
	}

	// Type heap input range
	printf("Type heap range: ");
	scanf("%d", &range);

	// ft_init_heap
	ft_init_heap(heap, size, range);

	// print initialized heap
	ft_println(1);
	printf("Initialized heap: ");
	ft_print_heap(heap, size);

	// ft_make_heap
	ft_make_heap(heap, size);

	// print heapified heap
	ft_println(1);
	printf("Heapified heap: ");
	ft_print_heap(heap, size);

	// Type inserted heap
	ft_println(1);
	printf("Type inserting heap: ");
	scanf("%d", &input);
	
	// ft_insert_heap
	heap = ft_insert_heap(heap, size, input);
	size++;

	// print inserted heap
	ft_println(1);
	printf("Inserted heap: ");
	ft_print_heap(heap, size);

	// ft_find_max_heap
	ft_println(1);
	printf("Max heap: %d\n", ft_find_max_heap(heap));

	// ft_remove_max_heap
	heap = ft_delete_max_heap(heap, size);
	size--;

	// print rearranged heap
	ft_println(1);
	printf("Rearranged heap: ");
	ft_print_heap(heap, size);

	// ft_remove_max_heap
	heap = ft_delete_max_heap(heap, size);
	size--;

	// print rearranged heap
	ft_println(1);
	printf("Rearranged heap: ");
	ft_print_heap(heap, size);
}