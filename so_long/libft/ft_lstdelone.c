/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:24:02 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 14:09:20 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst || del)
	{
		del(lst->list_position);
		del(lst->x);
		del(lst->y);
		free(lst);
	}
}
