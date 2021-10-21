/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:53:12 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/06 21:53:13 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, \
	   void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		*root = btree_create_node(item);
	else if (cmpf((*root)->item, item) < 0)
		btree_insert_data(&(*root)->right, item, cmpf);
	else
		btree_insert_data(&(*root)->left, item, cmpf);
}
