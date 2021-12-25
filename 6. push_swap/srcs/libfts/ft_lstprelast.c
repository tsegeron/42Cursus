/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprelast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:59:17 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/19 23:59:17 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/push_swap.h"

t_list	*ft_lstprelast(t_list *lst)
{
	if (lst)
		if ((lst->next->next))
			return (ft_lstprelast(lst->next));
	return (lst);
}
