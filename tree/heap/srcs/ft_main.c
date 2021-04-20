#include "../includes/ft_heap.h"

int		main(void)
{
	int		*heap;
	int		size;
	int		range;
	int		i;

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
}