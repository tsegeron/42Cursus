
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

t_list *ft_create_elem(void *data)
{
    t_list *elem1;
    
    elem1 = malloc(sizeof(t_list));
    if (elem1 == NULL)
        return (0);
    elem1->data = data;
    elem1->next = NULL;
    return (elem1);
}

t_list *ft_list_push_strs(int size, char **strs)
{
    if(*begin_list == 0)
        begin_list = ft_create_elem(data);
    else
        while(begin_list != NULL)
            begin_list = begin_list->next
    begin_list = ft_create_elem(data);
}
