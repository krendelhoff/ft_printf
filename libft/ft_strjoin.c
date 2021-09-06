#include "libft.h"

static char	*write_into(char const *s, char *iter)
{
	size_t	i;

	i = 0;
	while (s[i])
		*iter++ = s[i++];
	return (iter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*newstr;
	char	*iter;

	if (!s1)
		s1len = 0;
	else
		s1len = ft_strlen(s1);
	if (!s2)
		s2len = 0;
	else
		s2len = ft_strlen(s2);
	newstr = (char *)ft_calloc(s1len + s2len + 1, sizeof(*newstr));
	if (!newstr)
		return (NULL);
	iter = newstr;
	if (s1)
		iter = write_into(s1, iter);
	if (s2)
		iter = write_into(s2, iter);
	*iter = '\0';
	return (newstr);
}
