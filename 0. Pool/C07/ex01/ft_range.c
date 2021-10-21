/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:30:20 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/30 21:43:51 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*p;

	i = 0;
	if (min >= max)
		return (0);
	p = (int *) malloc((max - min) * sizeof(int));
	if (NULL == p)
		return (0);
	while (i != max - min)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}
