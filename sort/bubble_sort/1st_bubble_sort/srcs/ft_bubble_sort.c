#include "../includes/ft_bubble_sort.h"

void	ft_bubble_sort(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = size;
	while (--i >= 0)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}