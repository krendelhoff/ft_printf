#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	srclen = ft_strlen(src);
	while (*dst)
	{
		if (dstlen == dstsize)
			break ;
		dstlen++;
		dst++;
	}
	if (dstsize > dstlen)
	{
		while (*src && dstsize-- - dstlen > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (dstlen + srclen);
}
