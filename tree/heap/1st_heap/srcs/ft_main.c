#include "../includes/ft_heap.h"

int		main(void)
{
	int		*heap;
	int		size;
	int		range;
	int		i;
	int		*re_heap;

	printf("Type heap size: ");
	scanf("%d", &size);
	heap = ft_create_heap(size);
	printf("Type heap range: ");
	scanf("%d", &range);
	srand((unsigned int)time(NULL));
	i = -1;
	while (++i < size)
		heap[i] = rand() % range;
	i = -1;
	printf("\nInitial Heap: ");
	while (++i < size)
		printf("%d ", heap[i]);
	printf("\n");
	ft_make_heap(heap, size);
	i = -1;
	printf("\nHeapified Heap: ");
	while (++i < size)
		printf("%d ", heap[i]);
	printf("\n");
	printf("Max Heap: %d\n", ft_max_heap(heap));
	printf("Max heap was deleted\n");
	re_heap = ft_delete_max_heap(heap, size);
	i = -1;
	printf("\nRearranged Heap: ");
	while (++i < size - 1)
		printf("%d ", re_heap[i]);
	printf("\n");
}