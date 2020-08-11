#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "default.h"

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
