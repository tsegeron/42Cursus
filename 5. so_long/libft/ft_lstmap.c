/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:10:11 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/05 01:42:44 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

static t_list	*ft_get_new_struct(t_list *lst, int (*f)(int))
{
	t_list	*new;

	if (!f)
		new = ft_lstnew(lst->list_position, lst->x, lst->y);
	else
		new = ft_lstnew(f(lst->list_position), f(lst->x), f(lst->y));
	return (new);
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new_out;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return (NULL);
	new_out = ft_get_new_struct(lst, f);
	tmp2 = new_out;
	tmp = lst->next;
	lst = tmp;
	while (lst)
	{
		tmp2->next = ft_get_new_struct(lst, f);
		if (!tmp2->next)
		{
			if (del)
				ft_lstclear(&new_out, del);
			return (NULL);
		}
		lst = lst->next;
		tmp2 = tmp2->next;
	}
	return (new_out);
}
