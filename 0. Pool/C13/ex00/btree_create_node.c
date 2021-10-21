/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:41:15 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/06 21:41:18 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*derevo;

	derevo = malloc(sizeof(t_btree));
	if (derevo == NULL)
		return (0);
	derevo->item = item;
	derevo->left = 0;
	derevo->right = 0;
	return (derevo);
}
