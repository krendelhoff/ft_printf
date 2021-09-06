#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;
	char	*tmpptr;

	len = ft_strlen(s1);
	ptr = (char *)ft_calloc(len + 1, sizeof(*ptr));
	if (!ptr)
		return (NULL);
	tmpptr = ptr;
	while (*s1)
		*tmpptr++ = *s1++;
	*tmpptr = '\0';
	return (ptr);
}
