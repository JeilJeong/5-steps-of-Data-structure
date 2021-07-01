#include "../includes/ft_bubble_sort.h"

int		main(void)
{
	int		i;
	int		arr[MAX_SIZE];
	int		factor;
	long	start;
	long	end;

	srand(time(NULL));
	factor = MAX_SIZE * 100;
	i = -1;
	while (++i < MAX_SIZE)
		arr[i] = rand() % factor;
	start = clock();
	ft_bubble_sort(arr, MAX_SIZE);
	end = clock();
	printf("time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	// i = -1;
	// printf("sort: ");
	// while (++i < MAX_SIZE)
	// {
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");
}