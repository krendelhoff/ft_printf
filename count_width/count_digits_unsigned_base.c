#include "ft_printf.h"

static int	recdigits_unsigned(unsigned num, unsigned base)
{
	if (num == 0)
		return (0);
	else
		return (1 + recdigits_unsigned(num / base, base));
}

int	count_digits_unsigned_base(unsigned num, unsigned base)
{
	if (num == 0)
		return (1);
	else
		return (recdigits_unsigned(num, base));
}
