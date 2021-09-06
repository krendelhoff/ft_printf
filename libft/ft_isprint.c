#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 040 && c <= 077)
		|| (c >= 0100 && c <= 0176))
		return (1);
	else
		return (0);
}
