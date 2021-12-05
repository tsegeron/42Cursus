/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:13:22 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/05 01:36:59 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

t_list	*ft_lstnew(int content, int x, int y)
{
	t_list	*glist;

	glist = (t_list *) malloc(sizeof(t_list));
	if (glist)
	{
		glist->list_position = content;
		glist->x = x;
		glist->y = y;
		glist->next = NULL;
	}
	return (glist);
}
