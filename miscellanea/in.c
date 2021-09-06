#include "ft_printf.h"

int	in(char elem, const char *s)
{
	while (*s && *s != elem)
		s++;
	if (*s == elem)
		return (1);
	return (0);
}
