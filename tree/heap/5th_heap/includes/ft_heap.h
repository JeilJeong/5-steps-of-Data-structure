#ifndef FT_HEAP_H
# define FT_HEAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# define NORMAL		0
# define ABNORMAL	-1

// ft_heap.c
int		*ft_make_heap(int *heap, int size);
void	ft_heapify_down(int *heap, int range, int index);

// ft_print_utils.c
void	ft_println(int size);
void	ft_print_heap(int *heap, int size);

#endif