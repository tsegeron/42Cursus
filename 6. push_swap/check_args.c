/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:07:45 by gernesto          #+#    #+#             */
/*   Updated: 2021/11/11 10:31:46 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int **sorted, int start, int end)
{
	int *copied;
	int	i;

	i = 0;
	while (start < end)
		copied[i++] = (*sorted)[start++];
	return (copied);
}

void	do_sorting(int *sorted, int end)
{
	int *left_array;
	int *right_array;

	if (end < 2)
		return ;
	left_array = copy_array(&sorted, 0, end / 2);
	right_array = copy_array(&sorted, end / 2 + 1, end);

	left_array = do_sorting(left_array, end / 2);
	if (end % 2)
		end = end / 2 + 1;
	else
		end /= 2;
	right_array = do_sorting(right_array, end);
	int q,w = 0; //check
	while (q < end)
		printf("left  : %d\n", left_array[q++]);
	while (w < end)
		printf("right : %d\n", left_array[w++]);


	merge();
}

void	merge_sort(int **a, int end)
{
	int	*sorted;
	int	i;

	i = -1;
	while (++i != end)
		sorted[i] = (*a)[i];
	if (end < 2)
		return ;
	else
		do_sorting(&sorted, 0, end);
}

int	check_args(int **a, int **b, int ac, char *av[])
{
	int	check_zero;
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
