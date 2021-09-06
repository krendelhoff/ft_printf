#include "libft.h"

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 'a' + 'A');
	return (c);
}
