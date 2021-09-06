#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (!s)
		return (NULL);
	newstr = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(*newstr));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
