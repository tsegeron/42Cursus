/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:58:42 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/10 07:40:21 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/push_swap.h"

static int	display_error(void)
{
	write (1, ERROR, 7);
	return (0);
}

static int	create_stacks(int **a, int **b, int **sorted, int ac)
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
	*sorted = malloc(sizeof(int) * (ac - 1));
	if (!*sorted)
	{
		free (*a);
		free (*b);
		return (0);
	}
	return (1);
}

static void	fill_sorted(int **a, int **sorted, int ac)
{
	size_t	i;

	i = -1;
	while (++i < ac - 1)
		(*sorted)[i] = (*a)[i];
	merge_sort(*sorted, 0, ac - 2);
}

static void	printArray(int ac, int *array)
{
	for (int i = 0; i < ac - 1; i++)
		printf("%d ", array[i]);
}

int	main(int ac, char *av[])
{
	int	*a;
	int	*b;
	int	*sorted;

	if (!(create_stacks(&a, &b, &sorted, ac)) || !(check_args(&a, &b, ac, ++av)))
		return (display_error());
	fill_sorted(&a, &sorted, ac);




	printf("Given\n");
	printArray(ac, a);
	printf("\nSorted\n");
	printArray(ac, sorted);






	free (a);
	free (b);
	free (sorted);

	return (0);
}
