#include "libft.h"

static size_t	check(const char *haystack, const char *needle, size_t len)
{
	size_t	count;

	count = 0;
	while (*haystack == *needle && *haystack && len--)
	{
		needle++;
		haystack++;
		count++;
	}
	return (count);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;
	size_t	step;

	needlelen = ft_strlen(needle);
	if (needlelen > 0)
	{
		while (len && *haystack)
		{
			step = check(haystack, needle, len--);
			if (step == needlelen)
				return ((char *)haystack);
			if (step > 0)
				haystack += step;
			else
				haystack++;
		}
		return (NULL);
	}
	else
		return ((char *)haystack);
}
