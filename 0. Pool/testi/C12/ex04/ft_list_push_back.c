/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:48:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/05 19:48:20 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
    if(*begin_list == 0)
        begin_list = ft_create_elem(data);
    else
        while(begin_list != NULL)
            begin_list = begin_list->next;
    begin_list = ft_create_elem(data);
}
