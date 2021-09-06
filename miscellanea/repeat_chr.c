#include "ft_printf.h"

void	repeat_chr(int c, int n)
{
	if (n >= 0)
		while (n--)
			ft_putchar(c);
}
