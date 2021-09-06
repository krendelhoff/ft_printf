#include "ft_printf.h"

int	count_width(int mode, void *data)
{
	if (mode == 'd' || mode == 'i')
		return (count_digits(*((int *)data)));
	else if (mode == 's' && ((*((char **)data)) == NULL))
		return (6);
	else if (mode == 's')
		return (ft_strlen(*((char **)data)));
	else if (mode == 'x' || mode == 'X')
		return (count_digits_unsigned_base(*((unsigned *)data), 16));
	else if (mode == 'u')
		return (count_digits_unsigned_base(*((unsigned *)data), 10));
	else if (mode == '%' || mode == 'c')
		return (1);
	else if (mode == 'p')
		return (2 + count_digits_ptr(*((void **)data)));
	return (0);
}
