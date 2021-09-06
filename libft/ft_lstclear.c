#include "libft.h"

static void	rec(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		rec(lst->next, del);
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst)
	{
		rec(*lst, del);
		*lst = NULL;
	}
}
