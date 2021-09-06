#include "ft_printf.h"

static void	negative_case(t_item *item, int opt_zeros, int opt_spaces, int sign)
{
	if (sign)
		ft_putchar('-');
	repeat_chr('0', opt_zeros);
	if (item -> pure_width)
		ft_putnbr(*((int *)item -> data));
	repeat_chr(' ', opt_spaces);
}

static void	non_negative_case(t_item *item, int opt_zeros,
		int opt_spaces, int sign)
{
	if ((!item -> point || item -> precision_failed) && item -> zero)
	{
		if (sign)
			ft_putchar('-');
		supplement(item, opt_spaces);
	}
	else
	{
		supplement(item, opt_spaces);
		if (sign)
			ft_putchar('-');
	}
	repeat_chr('0', opt_zeros);
	if (item -> pure_width)
		ft_putnbr(*((int *)item -> data));
}

int	print_int(t_item *item)
{
	int	opt_zeros;
	int	opt_spaces;
	int	sign;

	if (item -> point && !(*((unsigned *)item -> data))
		&& !item -> precision)
		item -> pure_width = 0;
	sign = ((*((int *)item -> data)) < 0);
	opt_zeros = max(item -> precision - item -> pure_width, 0);
	opt_spaces = max(item -> padding - opt_zeros - item -> pure_width - sign,
			0);
	if (item -> negative)
		negative_case(item, opt_zeros, opt_spaces, sign);
	else
		non_negative_case(item, opt_zeros, opt_spaces, sign);
	return (opt_zeros + opt_spaces + item -> pure_width + sign);
}
