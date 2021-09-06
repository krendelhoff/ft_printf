#include "libft.h"

static int	rec(t_list *new, t_list *lst, void *(*f)(void *),
	   	void (*del)(void *))
{
	if (lst->next)
	{
		new->next = ft_lstnew((*f)(lst->next->content));
		if (!new->next)
			return (0);
		return (rec(new->next, lst->next, f, del));
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	len;
	t_list	*new;

	if (lst)
	{
		len = ft_lstsize(lst);
		if (len > 0)
		{
			new = ft_lstnew((*f)(lst->content));
			if (!new)
				return (NULL);
			if (rec(new, lst, f, del))
				return (new);
			else
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
