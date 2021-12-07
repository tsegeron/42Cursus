/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:30:26 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 16:36:47 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	if ((lst->next) == NULL)
		return (1);
	else
		return (ft_lstsize(lst->next) + 1);
}
