/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:01:30 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 16:07:24 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst != NULL)
	{
		f(lst->x);
		f(lst->y);
		lst = lst->next;
	}
}
