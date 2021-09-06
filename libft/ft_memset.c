#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmpb;

	tmpb = b;
	while (len--)
		*tmpb++ = (unsigned char)c;
	return (b);
}
