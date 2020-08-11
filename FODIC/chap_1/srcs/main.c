#include <stdio.h>
#include <time.h>
#include "default.h"
#include "selection_sort.h"

int		main(void)
{
	int			*arr;
	clock_t		start;
	clock_t		end;
	double		result;

	start = clock();

	MALLOC(arr, sizeof(int));
	ft_insert_num(arr);
//	ft_print_arr(arr);
	ft_selection_sort(arr);
//	ft_print_arr(arr);

	end = clock();
	result = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("execution time: %lf\n", result);
}
