#ifndef FT_HEAP_H
# define FT_HEAP_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

// ft_crud_heap.c
int		*ft_create_heap(int size);
void	ft_init_heap(int *heap, int size, int range);
int		*ft_delete_max_heap(int *heap, int size);
int		*ft_rearrange_heap(int *heap, int size);
int		*ft_insert_heap(int *heap, int size, int input);

// ft_print_utils.c
void	ft_print_heap(int *heap, int size);
void	ft_println(int size);

// ft_heap_utils.c
int		ft_max_index(int *heap, int index, int left, int right);
void	ft_make_heap(int *heap, int size);
void	ft_heapify_up(int *heap, int index);
void	ft_heapify_down(int *heap, int index, int size);
int		ft_find_max_heap(int *heap);

#endif