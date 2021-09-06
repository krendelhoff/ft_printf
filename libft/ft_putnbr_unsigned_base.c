#include "libft.h"

static void	rec(unsigned n, unsigned base, char mode)
{
	int	ch;

	if (n / base != 0)
		rec(n / base, base, mode);
	ch = n % base;
	ft_putchar(convert(ch, mode));
}

void	ft_putnbr_unsigned_base(unsigned n, unsigned base, char mode)
{
	if (n == 0)
		ft_putchar('0');
	else
		rec(n, base, mode);
}
