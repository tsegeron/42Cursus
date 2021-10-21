/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:27:14 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/05 23:27:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*structure;

	if (size == 0)
		return (0);
	while (size >= 0)
	{
		structure = ft_create_elem(void *(strs[size - 1]));
		size--;
		structure = structure->next;
	}
	return (*structure);
}
