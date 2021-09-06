#include "ft_printf.h"

void	*read_value(int conv, va_list ap)
{
	if (conv == 'd' || conv == 'i' || conv == 'c')
		return (read_int(ap));
	else if (conv == 'p')
		return (read_p(ap));
	else if (conv == 's')
		return (read_s(ap));
	else if (conv == 'x' || conv == 'X' || conv == 'u')
		return (read_unsigned(ap));
	else if (conv == '%')
		return (read_per());
	return (NULL);
}
