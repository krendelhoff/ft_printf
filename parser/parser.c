#include "ft_printf.h"

static void	clear(t_item *item)
{
	free(item -> data);
	free(item);
}

static int	make_proper_precision(int precision, int pure_width, t_item *item)
{
	if (precision < 0)
	{
		item -> precision_failed = 1;
		return (pure_width);
	}
	return (precision);
}

int	parse(va_list ap, char **format)
{
	t_item	*item;
	int		res;

	(*format)++;
	item = parse_item(format, ap);
	if (!item)
		return (0);
	if (item -> failed)
	{
		clear(item);
		return (0);
	}
	item -> data = read_value(item -> conversion, ap);
	if (!(item -> data))
	{
		clear(item);
		return (0);
	}
	item -> pure_width = count_width(item -> conversion, item -> data);
	item -> precision = make_proper_precision(item -> precision,
			item -> pure_width, item);
	res = print(item);
	clear(item);
	return (res);
}
