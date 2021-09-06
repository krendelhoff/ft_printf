#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	flag;
	size_t	i;
	size_t	count;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i++] != c)
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
		}
		else
			flag = 0;
	}
	return (count);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*ptr;
	char	*tmpptr;

	len = ft_strlen(s1);
	if (len > n)
		len = n;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	tmpptr = ptr;
	while (n-- && *s1)
		*tmpptr++ = *s1++;
	*tmpptr = '\0';
	return (ptr);
}

static void	freesplit(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static char	**write_into(char **split, char *s, int c)
{
	char	**initial;	
	size_t	count;

	initial = split;
	while (*s)
	{
		count = 0;
		while (*(s + count) && *(s + count) != c)
			count++;
		if (count > 0)
		{
			*split = ft_strndup(s, count);
			if (!*split++)
			{
				freesplit(initial);
				return (NULL);
			}
			s += count;
		}
		else
			s++;
	}
	return (initial);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	split = (char **)ft_calloc(words + 1, sizeof(*split));
	if (!split)
		return (NULL);
	split = write_into(split, (char *)s, c);
	return (split);
}
