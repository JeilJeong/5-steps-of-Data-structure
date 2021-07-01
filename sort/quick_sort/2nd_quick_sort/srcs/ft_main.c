#include "../includes/ft_quick_sort.h"

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
	// printf("rand: ");
	while (++i < MAX_SIZE)
	{
		arr[i] = rand() % factor;
		// printf("%d ", arr[i]);
	}
	// printf("\n");
	start = clock();
	ft_quick_sort(arr, 0, MAX_SIZE - 1);
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
