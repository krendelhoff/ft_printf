#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	count(int n, int i)
{
	if (n != 0)
		return (count(n / 10, i + 1));
	else
		return (i);
}

static void	writestr(char *str, int n, int count)
{
	if (n / 10 != 0)
		writestr(str, n / 10, count - 1);
	str[count] = ft_abs(n % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*newstr;
	int		size;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (n != 0)
		size = count(n, 0) + sign + 1;
	else
		size = 2;
	newstr = (char *)ft_calloc(size, sizeof(*newstr));
	if (!newstr)
		return (NULL);
	if (sign)
		newstr[0] = '-';
	if (n != 0)
		writestr(newstr, n, size - 2);
	else
		newstr[0] = '0';
	newstr[size - 1] = '\0';
	return (newstr);
}
