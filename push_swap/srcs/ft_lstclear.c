/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:11:55 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/10 19:50:30 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*prev_ptr;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		prev_ptr = tmp->next;
//		del(tmp->list_position);
//		del(tmp->x);
//		del(tmp->y);
		free(tmp);
		tmp = prev_ptr;
	}
	*lst = NULL;
}
