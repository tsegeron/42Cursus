/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:11:55 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 16:33:13 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*prev_ptr;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		prev_ptr = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = prev_ptr;
	}
	*lst = NULL;
}
