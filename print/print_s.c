#include "ft_printf.h"

static int	nullcase(t_item *item, int opt_spaces, int printlen)
{
	if (item -> negative)
	{
		ft_putstr_n("(null)", printlen);
		repeat_chr(' ', opt_spaces);
	}
	else
	{
		repeat_chr(' ' * (!(item -> zero)) + '0' * (item -> zero), opt_spaces);
		ft_putstr_n("(null)", printlen);
	}
	return (opt_spaces + printlen);
}

int	print_s(t_item *item)
{
	int	opt_spaces;
	int	printlen;

	if (item -> point)
		printlen = min(item -> precision, item -> pure_width);
	else
		printlen = item -> pure_width;
	opt_spaces = max(item -> padding - printlen, 0);
	if (!(*((char **)item -> data)))
		return (nullcase(item, opt_spaces, printlen));
	if (item -> negative)
	{
		ft_putstr_n(*((char **)item -> data), printlen);
		repeat_chr(' ', opt_spaces);
	}
	else
	{
		repeat_chr(' ' * (!(item -> zero)) + '0' * (item -> zero), opt_spaces);
		ft_putstr_n(*((char **)item -> data), printlen);
	}
	return (opt_spaces + printlen);
}
