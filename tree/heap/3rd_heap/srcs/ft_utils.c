#include "../includes/ft_heap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	char			ch;
	size_t			i;

	ptr = (unsigned char *)s;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = ch;
		i++;
	}
	return ((void *)ptr);
}