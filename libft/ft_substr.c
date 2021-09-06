#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	char	*iter;
	size_t	substrlen;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		substrlen = 0;
	else
		substrlen = i - start;
	if (substrlen > len)
		substrlen = len;
	newstr = (char *)ft_calloc(substrlen + 1, sizeof(*newstr));
	if (!newstr)
		return (NULL);
	iter = newstr;
	i = start;
	while (substrlen-- && s[i])
		*iter++ = s[i++];
	*iter = '\0';
	return (newstr);
}
