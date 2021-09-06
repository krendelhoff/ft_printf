#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmps;

	tmps = (unsigned char *)s;
	while (n && *tmps)
	{
		if (*tmps == (unsigned char) c)
			return (tmps);
		tmps++;
		n--;
	}
	if (n > 0 && *tmps == (unsigned char) c)
		return (tmps);
	return (NULL);
}
