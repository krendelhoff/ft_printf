#include "ft_printf.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*parse_flags(char *tmp, t_item *item)
{
	while (in(*tmp, "-0"))
	{
		if (*tmp == '0')
			item -> zero = 1;
		else if (*tmp == '-')
			item -> negative = 1;
		tmp++;
	}
	return (tmp);
}

char	*parse_padding(char *tmp, t_item *item, va_list ap)
{
	if (*tmp == '*')
	{
		item -> padding = va_arg(ap, int);
		if (item -> padding < 0)
		{
			item -> padding = ft_abs(item -> padding);
			item -> negative = 1;
		}
		return (++tmp);
	}
	else
	{
		item -> padding = ft_atoi(tmp);
		if (ft_isdigit(*tmp))
			tmp += count_digits(item -> padding);
		return (tmp);
	}
}

char	*parse_precision(char *tmp, t_item *item, va_list ap)
{
	if (*tmp == '.')
	{
		item -> point = 1;
		tmp++;
		if (*tmp == '*')
		{
			item -> precision = va_arg(ap, int);
			return (++tmp);
		}
		else
		{
			item -> precision = ft_atoi(tmp);
			if (ft_isdigit(*tmp))
				tmp += count_digits(item -> precision);
			return (tmp);
		}
	}
	else
		return (tmp);
}

char	*parse_conversion(char *tmp, t_item *item)
{
	if (in(*tmp, "cspdiuxX%"))
	{
		item -> conversion = *tmp;
		tmp++;
	}
	else
		item -> failed = 1;
	return (tmp);
}
