#include "../includes/ft_quick_sort.h"

void	ft_quick_sort(int *arr, int start, int end)
{
	int		pivot;
	int		left;
	int		right;
	int		swap_tmp;

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
			swap_tmp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = swap_tmp;
		}
		else
		{
			swap_tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = swap_tmp;
		}
	}
	ft_quick_sort(arr, start, right - 1);
	ft_quick_sort(arr, right + 1, end);
}