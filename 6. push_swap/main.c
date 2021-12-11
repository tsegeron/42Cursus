/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:58:42 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/11 17:40:38 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	display_error(void)
{
	write (1, ERROR, 7);
	return (0);
}

static int	create_stacks(int **a, int **b, int ac)
{
	*a = malloc(sizeof(int) * (ac - 1));
	if (!*a)
		return (0);
	*b = malloc(sizeof(int) * (ac - 1));
	if (!*b)
	{
		free (*a);
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int	*a;
	int	*b;

	if (!(create_stacks(&a, &b, ac)) || !(check_args(&a, &b, ac, ++av)))
		return (display_error());







	while (--ac > 0)
		printf("%d\n", a[ac - 1]);

	free (a);
	free (b);

	return (0);
}
