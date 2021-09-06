#include "ft_printf.h"

int	print(t_item *item)
{
	if (item -> conversion == 'd' || item -> conversion == 'i')
		return (print_int(item));
	else if (item -> conversion == 'x')
		return (print_unsigned(item, 16, 'x'));
	else if (item -> conversion == 'X')
		return (print_unsigned(item, 16, 'X'));
	else if (item -> conversion == 'u')
		return (print_unsigned(item, 10, 'x'));
	else if (item -> conversion == 'c' || item -> conversion == '%')
		return (print_char(item));
	else if (item -> conversion == 's')
		return (print_s(item));
	else if (item -> conversion == 'p')
		return (print_p(item));
	return (0);
}
