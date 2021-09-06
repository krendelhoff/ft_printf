#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
		new->next = *lst;
	if (lst)
		*lst = new;
}
