#include "ft_printf.h"

static void	non_item_case(int *counter, char **format)
{
	ft_putchar(**format);
	(*counter)++;
	(*format)++;
}

static void	item_case(int *counter, char **format, va_list ap)
{
	int	sig;

	sig = parse(ap, format);
	(*counter) += sig;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;
	char	*tmp;

	va_start(ap, format);
	counter = 0;
	while (*format)
	{
		tmp = (char *)format;
		if (*format != '%')
			non_item_case(&counter, &tmp);
		else
			item_case(&counter, &tmp, ap);
		format = tmp;
	}
	va_end(ap);
	return (counter);
}
