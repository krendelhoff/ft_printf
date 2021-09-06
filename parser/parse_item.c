#include "ft_printf.h"

t_item	*parse_item(char **format, va_list ap)
{
	t_item	*item;

	item = ft_calloc(1, sizeof(t_item));
	if (!item)
		return (item);
	*format = parse_flags(*format, item);
	*format = parse_padding(*format, item, ap);
	*format = parse_precision(*format, item, ap);
	*format = parse_conversion(*format, item);
	return (item);
}
