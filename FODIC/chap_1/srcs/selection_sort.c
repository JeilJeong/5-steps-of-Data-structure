#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MALLOC(p, s) \
	if (!((p) = malloc((s) * (DEFAULT_SIZE)))) \
	{ \
		fprintf(stderr, "Insuffienct memory\n"); \
		exit(EXIT_FAILURE); \
	}
#define DEFAULT_SIZE 100

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_selection_sort(int *arr)
{
	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		for (int j = i; j < DEFAULT_SIZE; j++)
		{
			if (arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
		}
	}
}

void	ft_print_arr(int *arr)
{
	int		i;

	i = -1;
	while (++i < DEFAULT_SIZE)
	{
		if (i % 10 == 0)
		{
			fprintf(stdout, "\n");
		}
		printf("%d ", arr[i]);
	}
	fprintf(stdout, "\n");
}

void	ft_insert_num(int *arr)
{
	srand(time(NULL));
	for (int i  = 0; i < DEFAULT_SIZE; i++)
	{
		arr[i] = rand() % DEFAULT_SIZE;
	}
}

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
