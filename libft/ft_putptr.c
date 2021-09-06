#include "libft.h"

void	rec(size_t ptr)
{
	if (ptr / 16 != 0)
		rec(ptr / 16);
	ft_putchar(convert(ptr % 16, 'x'));
}

void	ft_putptr(void	*ptr)
{
	size_t	ptrvalue;

	ptrvalue = (size_t)ptr;
	ft_putstr("0x");
	if (!ptrvalue)
		ft_putchar('0');
	else
		rec(ptrvalue);
}
