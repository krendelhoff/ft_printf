#include "libft.h"

static long long	ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	rec(long long n, int fd)
{
	if (n / 10 != 0)
		rec(n / 10, fd);
	ft_putchar_fd(ft_abs(n % 10) + '0', fd);
}

void	ft_putnbr_fd(long long n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		rec(n, fd);
	}
}
