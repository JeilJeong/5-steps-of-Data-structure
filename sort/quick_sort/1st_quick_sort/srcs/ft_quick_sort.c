#include "../includes/ft_quick_sort.h"

void	ft_quick_sort(long *arr, int start, int end)
{
	int		pivot;
	int		left;
	int		right;
	int		tmp;

	if (!arr || start >= end)
		return ;
	pivot = start;
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left <= end && arr[left] <= arr[pivot])
			left += 1;
		while (right > start && arr[right] >= arr[pivot])
			right -= 1;
		if (left > right)
		{
			tmp = arr[pivot];
			arr[pivot] = arr[right];
			arr[right] = tmp;
		}
		else
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	ft_quick_sort(arr, start, right - 1);
	ft_quick_sort(arr, right + 1, end);
}