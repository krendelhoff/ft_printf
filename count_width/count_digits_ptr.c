#include "ft_printf.h"

static int	recdigits_ptr(size_t num)
{
	if (num == 0)
		return (0);
	else
		return (1 + recdigits_ptr(num / 16));
}

int	count_digits_ptr(void *ptr)
{
	size_t	num;

	num = (size_t) ptr;
	if (num == 0)
		return (1);
	else
		return (recdigits_ptr(num));
}
