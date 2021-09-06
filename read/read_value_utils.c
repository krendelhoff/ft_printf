#include "ft_printf.h"

void	*read_int(va_list ap)
{
	int	*value;

	value = ft_calloc(1, sizeof(int));
	if (!value)
		return (value);
	*value = va_arg(ap, int);
	return (value);
}

void	*read_s(va_list ap)
{
	char	**value;

	value = ft_calloc(1, sizeof(char *));
	if (!value)
		return (value);
	*value = va_arg(ap, char *);
	return (value);
}

void	*read_p(va_list ap)
{
	void	**value;

	value = ft_calloc(1, sizeof(void *));
	if (!value)
		return (value);
	*value = va_arg(ap, void *);
	return (value);
}

void	*read_unsigned(va_list ap)
{
	unsigned int	*value;

	value = ft_calloc(1, sizeof(unsigned int));
	if (!value)
		return (value);
	*value = va_arg(ap, unsigned int);
	return (value);
}

void	*read_per(void)
{
	char	*value;

	value = ft_calloc(2, sizeof(char));
	if (!value)
		return (value);
	*value = '%';
	return (value);
}
