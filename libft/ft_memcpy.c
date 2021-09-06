#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	if (!(dst || src))
		return (NULL);
	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	while (n--)
		*tmpdst++ = *tmpsrc++;
	return (dst);
}
