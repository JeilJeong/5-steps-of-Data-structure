#ifndef FT_HEAP_H
# define FT_HEAP_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define ABNORMAL	-1
# define NORMAL		0

// ft_crud_heap.c
int		*ft_create_heap(int size);
void	ft_init_heap(int *heap, int size, int range);
void	ft_make_heap(int *heap, int size);
int		*ft_insert_heap(int *heap, int size, int input);
int		*ft_delete_max_heap(int *heap, int size);

// ft_heap_utils.c
int		ft_max_index(int *heap, int index, int left, int right);
int		ft_min_index(int *heap, int index, int parent);
void	ft_heapify_up(int *heap, int index);
void	ft_heapify_down(int *heap, int size, int index);
int		ft_find_max_heap(int *heap);

// ft_print_utils.c
void	ft_print_heap(int *heap, int size);

// ft_utils.c
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *d, void *s, size_t n);

// ft_sort_heap.c
int		*ft_heap_sort(int *heap, int size);

#endif