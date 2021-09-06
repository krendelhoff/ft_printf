#include "ft_printf.h"

int	print_unsigned(t_item *item, unsigned int base, char mode)
{
	int	opt_zeros;
	int	opt_spaces;

	if (item -> point && !(*((unsigned *)item -> data))
		&& !item -> precision)
		item -> pure_width = 0;
	opt_zeros = max(item -> precision - item -> pure_width, 0);
	opt_spaces = max(item -> padding - opt_zeros - item -> pure_width, 0);
	if (item -> negative)
	{
		repeat_chr('0', opt_zeros);
		if (item -> pure_width)
			ft_putnbr_unsigned_base(*((unsigned *)item -> data), base, mode);
		repeat_chr(' ', opt_spaces);
	}
	else
	{
		supplement(item, opt_spaces);
		repeat_chr('0', opt_zeros);
		if (item -> pure_width)
			ft_putnbr_unsigned_base(*((unsigned *)item -> data), base, mode);
	}
	return (opt_zeros + opt_spaces + item -> pure_width);
}
