/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:53:57 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/05 22:53:58 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem1;

	elem1 = malloc(sizeof(t_list));
	if (elem1 == NULL)
		return (0);
	elem1->data = data;
	elem1->next = NULL;
	return (elem1);
}
