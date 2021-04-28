#include "../includes/ft_heap.h"

int		main(void)
{
	int		*heap;
	int		size;
	int		range;
	int		input;
	// int		*sorted_heap;
	clock_t	start;
	clock_t	end;

	printf("Type heap size: ");
	scanf("%d", &size);

	printf("Type heap range: ");
	scanf("%d", &range);

	// ft_create_heap
	if (!(heap = ft_create_heap(size)))
	{
		printf("alloc error: main\n");
		return (ABNORMAL);
	}

	// ft_init_heap
	ft_init_heap(heap, size, range);

	printf("Init heap: ");
	ft_print_heap(heap, size);

	// ft_make_heap
	ft_make_heap(heap, size);

	printf("Maked heap: ");
	ft_print_heap(heap, size);

	// ft_insert_heap
	printf("Type inserted num: ");
	scanf("%d", &input);
	if (!(heap = ft_insert_heap(heap, size, input)))
	{
		printf("alloc error: main\n");
		return (ABNORMAL);
	}
	size += 1;

	printf("Inserted heap: ");
	ft_print_heap(heap, size);

	// ft_find_max_heap
	printf(">>> Max heap value: %d\n", ft_find_max_heap(heap));

	// ft_delete_max_heap
	while (heap)
	{
		printf("[1] Continue deletion	[2] Break\n");
		printf(">>> ");
		scanf("%d", &input);
		if (input == 1)
		{
			if (!(heap = ft_delete_max_heap(heap, size)))
			{
				printf("alloc error: main\n");
				return (ABNORMAL);
			}
			size -= 1;
			printf("Deleted heap: ");
			ft_print_heap(heap, size);
		}
		else if (input == 2)
			break;
	}

	// ft_heap_sort
	// start = clock();
	// if (!(sorted_heap = ft_heap_sort(heap, size)))
	// {
	// 	printf("alloc error: main\n");
	// 	return (ABNORMAL);
	// }
	// end = clock();

	// printf("Sorted heap: ");
	// ft_print_heap(sorted_heap, size);
	start = clock();
	printf("Sorted heap: ");
	heap = ft_heap_sort_print_version(heap, size);
	end = clock();
	free(heap);
	// free(sorted_heap);
	printf("time = %f\n", (float)(end - start) / CLOCKS_PER_SEC);
	return (NORMAL);
}