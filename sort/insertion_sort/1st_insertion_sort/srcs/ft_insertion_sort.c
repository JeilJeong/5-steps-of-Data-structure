#include "../includes/ft_insertion_sort.h"

void	ft_insertion_sort(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;
	int		tmp_index;
	int		min_index;

	i = 0;
	while (++i < size)
	{
		j = i;
		while (--j >= 0)
		{
			if (arr[i] > arr[j])
			{
				min_index = j + 1;
				tmp = arr[i];
				tmp_index = i;
				while (--tmp_index > j)
					arr[tmp_index + 1] = arr[tmp_index];
				arr[min_index] = tmp;
				break;
			}
		}
		if (j < 0)
		{
			tmp = arr[i];
			tmp_index = i;
			while (--tmp_index >= 0)
				arr[tmp_index + 1] = arr[tmp_index];
			arr[0] = tmp;
		}
	}
}