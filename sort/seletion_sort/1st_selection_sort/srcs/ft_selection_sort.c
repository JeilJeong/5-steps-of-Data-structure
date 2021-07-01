#include "../includes/ft_selection_sort.h"

void	ft_selection_sort(int *arr, int size)
{
	int		i;
	int		j;
	int		min_index;
	int		tmp;

	if (!arr)
		return ;
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		min_index = i;
		while (++j < size)
			min_index = arr[min_index] < arr[j] ? min_index : j;
		if (min_index != i)
		{
			tmp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = tmp;
		}
	}
}