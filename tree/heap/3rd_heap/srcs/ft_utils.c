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

void	*ft_memcpy(void *d, void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;
	
	dest = d;
	src = s;
	i = 0;
	if (!d || !s)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}