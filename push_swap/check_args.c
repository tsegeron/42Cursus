/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:07:45 by gernesto          #+#    #+#             */
/*   Updated: 2021/11/30 14:48:27 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int **a, int **b, int ac, char *av[])
{
	int		check_zero;
	int	i;

	i = -1;
	if (ac < 2)
		return (0);
	while (*av)
	{
		check_zero = 0;
		(*a)[++i] = ft_atoi(*av++, &check_zero);
		if (!((*a)[i]) && !check_zero)
		{
			free (*a);
			free (*b);
			return (0);
		}
	}
	return (1);
}
