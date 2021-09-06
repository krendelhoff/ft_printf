#include "libft.h"

int	convert(int c, int mode)
{
	if (c < 10)
		return (c + '0');
	else if (c == 10)
		return ('a' * (mode == 'x') + 'A' * (mode != 'x'));
	else if (c == 11)
		return ('b' * (mode == 'x') + 'B' * (mode != 'x'));
	else if (c == 12)
		return ('c' * (mode == 'x') + 'C' * (mode != 'x'));
	else if (c == 13)
		return ('d' * (mode == 'x') + 'D' * (mode != 'x'));
	else if (c == 14)
		return ('e' * (mode == 'x') + 'E' * (mode != 'x'));
	else
		return ('f' * (mode == 'x') + 'F' * (mode != 'x'));
}
