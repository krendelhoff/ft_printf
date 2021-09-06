#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	if (!src)
		return (0);
	srclen = ft_strlen(src);
	if (dstsize > 0 && dst)
	{
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (srclen);
}
