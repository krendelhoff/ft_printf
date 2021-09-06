#include "ft_printf.h"

void	ft_putstr_n(char *s, int n)
{
	while (*s && n--)
		ft_putchar(*s++);
}
