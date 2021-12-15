#include "../../hdrs/push_swap.h"

t_list	*ft_lstprelast(t_list *lst)
{
	if (lst)
		if ((lst->next->next))
			return (ft_lstprelast(lst->next));
	return (lst);
}
