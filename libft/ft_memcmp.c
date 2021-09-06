#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	if (!(s1 || s2))
		return (0);
	if (n == 0)
		return (n);
	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	while (n-- && (*tmps1 == *tmps2))
	{
		if (n > 0)
		{
			tmps1++;
			tmps2++;
		}
	}
	return (*tmps1 - *tmps2);
}
