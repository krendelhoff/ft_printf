#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	return_value(size_t symbols, int sign, ssize_t n)
{
	if (symbols > 19 || (symbols == 19 && n < 0))
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	else
		return (sign * (int) n);
}

int	ft_atoi(const char *str)
{
	ssize_t	n;
	char	c;
	int		sign;
	size_t	symbols;

	sign = 1;
	symbols = 0;
	while (ft_isspace(*str))
		str++;
	n = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		c = *str++;
		n = (n * 10) + (c - '0');
		symbols++;
	}
	return (return_value(symbols, sign, n));
}
