#include "libft.h"

static int	rec(t_list *lst, int n)
{
	if (lst->next)
		return (rec(lst->next, n + 1));
	return (n);
}

int	ft_lstsize(t_list *lst)
{
	if (lst)
		return (rec(lst, 1));
	return (0);
}
