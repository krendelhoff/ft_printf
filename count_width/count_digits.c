#include "ft_printf.h"

static int	recdigits(int num)
{
	if (num == 0)
		return (0);
	else
		return (1 + recdigits (num / 10));
}

int	count_digits(int num)
{
	if (num == 0)
		return (1);
	else
		return (recdigits(num));
}
