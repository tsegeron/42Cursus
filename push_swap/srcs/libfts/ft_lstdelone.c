/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:24:02 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/10 19:43:06 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/push_swap.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst)
	{
//		del(lst->list_position);
//		del(lst->num);
//		del(lst->i);
		free(lst);
	}
}
