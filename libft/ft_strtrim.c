#include "libft.h"

static int	check(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static int	count(char const *s1, int strlen, char const *set, int flag)
{
	int		count;
	char	*tmps;

	count = 0;
	if (flag == 0)
	{
		tmps = (char *)s1;
		while (check(*tmps++, set))
			count++;
	}
	else
	{
		tmps = (char *)(s1 + strlen - 1);
		while (check(*(tmps - count), set))
			count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1len;
	size_t	start;
	size_t	end;
	char	*tmps1;
	char	*newstr;

	if (!s1)
		return (NULL);
	start = count(s1, (s1len = ft_strlen(s1)), set, 0);
	end = 0;
	if (start < s1len)
		end = count(s1, s1len, set, 1);
	if (start + end < s1len)
		s1len = s1len - start - end;
	else
		s1len = 0;
	newstr = (char *)ft_calloc(s1len + 1, sizeof(*newstr));
	if (!newstr)
		return (NULL);
	tmps1 = (char *)(s1 + start);
	end = 0;
	while (s1len--)
		newstr[end++] = *tmps1++;
	newstr[end] = '\0';
	return (newstr);
}
