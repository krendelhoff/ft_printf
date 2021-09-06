#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	rec(int n)
{
	if (n / 10 != 0)
		rec(n / 10);
	ft_putchar(ft_abs(n % 10) + '0');
}

void	ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else
		rec(n);
}
