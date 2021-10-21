/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 23:28:05 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/06 23:28:07 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	sizeL;
	int	sizeR;

	sizeL = 0;
	sizeR = 0;
	if (root->left != NULL && root->left != NULL)
	{
		sizeL = btree_level_count(root->left) + 1;
		sizeR = btree_level_count(root->right) + 1;
		if (sizeL > sizeR)
			return (sizeL);
		else
			return (sizeR);
	}
	return (0);
}
