#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == c)
			tmp = (char *)s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (tmp);
}
