#include "../includes/ft_heap.h"

int		main(void)
{
	int		i;
	int		size;
	int		range;
	int		*heap;
	
	printf("	Size: ");
	scanf("%d", &size);
	printf("	Range: ");
	scanf("%d", &range);
	if (!(heap = (int *)calloc(size, sizeof(int))))
	{
		printf("	malloc error: heap allocation\n");
		return (ABNORMAL);
	}
	i = -1;
	srand(time(NULL));
	while (++i < size)
		heap[i] = rand() % range;
	
	// print heap
	printf("	Init heap: ");
	ft_print_heap(heap, size);
	ft_println(1);

	// ft_make_heap()
	ft_make_heap(heap, size);

	// ft_print_heap()
	printf("	Maked heap: ");
	ft_print_heap(heap, size);
	ft_println(1);
}