#include <stdio.h>
#include "default.h"

void	sub_b_re_search(int *arr, int target, int start, int end)
{
	int	mid;

	mid = (start + end) / 2;
	if (arr[mid] == target)
	{
		printf("%d exist in arr[%d]\n", target, mid);
		return ;
	}
	else if (start == end)
	{
		printf("%d does not exist in arr\n", target);
		return ;
	}
	else if (arr[mid] > target)
	{
		end = mid - 1;
		sub_b_re_search(arr, target, start, end);
		return ;
	}
	else if (arr[mid] < target)
	{
		start = mid + 1;
		sub_b_re_search(arr, target, start, end);
		return ;
	}
}

void	b_recursive_search(int *arr, int target)
{
	int	start;
	int	end;
	
	start = 0;
	end = DEFAULT_SIZE - 1;
	sub_b_re_search(arr, target, start, end);
	return ;
}

void	b_iterative_search(int *arr, int target)
{
	int	start;
	int 	end;
	int	mid;

	start = 0;
	end = DEFAULT_SIZE;
	mid = (start + end) / 2;
	while(start != end)
	{
		if (arr[mid] == target)
		{
			printf("%d exist in arr[%d]\n", target, mid);
			return ;
		}
		else if (arr[mid] > target)
			end = mid - 1;
		else if (arr[mid] < target)
			start = mid + 1;
		mid = (start + end) / 2;
	}
	if (arr[mid] == target)
	{
		printf("%d exist in arr[%d]\n", target, mid);
	}
	else
		printf("%d does not exist in arr\n", target);
	return ;
}
