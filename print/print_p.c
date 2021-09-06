#include "ft_printf.h"

int	print_p(t_item *item)
{
	int	opt_spaces;

	opt_spaces = max(item -> padding - item -> pure_width, 0);
	if (item -> negative)
	{
		ft_putptr(*((void **)item -> data));
		repeat_chr(' ', opt_spaces);
	}
	else
	{
		repeat_chr(' ' * (!(item -> zero)) + '0' * (item -> zero), opt_spaces);
		ft_putptr(*((void **)item -> data));
	}
	return (opt_spaces + item -> pure_width);
}
