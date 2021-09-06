#include "ft_printf.h"

void	supplement(t_item *item, int opt_spaces)
{
	if (item -> point && !item -> precision_failed)
		repeat_chr(' ', opt_spaces);
	else
		repeat_chr(' ' * (!(item -> zero)) + '0' * (item -> zero),
			opt_spaces);
}
