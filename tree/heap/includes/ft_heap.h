#ifndef FT_HEAP_H
# define FT_HEAP_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

// ft_heap.c
int		*ft_create_heap(int size);
void	ft_make_heap(int *heap, int size);
void	ft_heapify_down(int *heap, int index, int size);
int		ft_max_index(int *heap, int index, int left, int right);

#endif