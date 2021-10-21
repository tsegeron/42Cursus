/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:13:07 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/30 21:48:24 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*p;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	p = (int *) malloc((max - min) * sizeof(int));
	if (NULL == p)
	{
		*range = 0;
		return (-1);
	}
	*range = p;
	while (i != max - min)
	{
		p[i] = min + i;
		i++;
	}
	return (max - min);
}
