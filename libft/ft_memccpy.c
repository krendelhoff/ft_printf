#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	unsigned char	ch;

	if (!(dst || src))
		return (NULL);
	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	ch = c;
	while (n--)
	{
		*tmpdst++ = *tmpsrc;
		if (*tmpsrc++ == ch)
			break ;
	}
	if (*(--tmpsrc) == ch)
		return ((void *)tmpdst);
	else
		return (NULL);
}
