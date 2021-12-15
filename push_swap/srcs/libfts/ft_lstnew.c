/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:13:22 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/10 10:50:47 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/push_swap.h"

t_list	*ft_lstnew(int num, int i)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (list)
	{
		list->num = num;
		list->i = i;
//		list->prev = NULL;
		list->next = NULL;
	}
	return (list);
}
