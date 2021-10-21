/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:10:11 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/12 04:43:22 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_get_new_struct(t_list *lst, void *(*f)(void *))
{
	t_list	*new;

	if (!f)
		new = ft_lstnew(lst->content);
	else
		new = ft_lstnew(f(lst->content));
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_out;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return (NULL);
	tmp = lst;
	new_out = ft_get_new_struct(lst, f);
	if (!new_out)
		return (NULL);
	tmp2 = new_out;
	tmp = tmp->next;
	while (tmp)
	{
		tmp2->next = ft_get_new_struct(lst, f);
		if (!tmp2->next)
		{
			if (del)
				ft_lstclear(&new_out, del);
			return (NULL);
		}
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	return (new_out);
}
