#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	if (!(dst || src))
		return (NULL);
	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	if (tmpdst > tmpsrc && tmpsrc + len > tmpdst)
		while (len--)
			*(tmpdst + len) = *(tmpsrc + len);
	else
		while (len--)
			*tmpdst++ = *tmpsrc++;
	return (dst);
}
