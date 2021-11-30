/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:58:42 by gernesto          #+#    #+#             */
/*   Updated: 2021/11/11 10:46:07 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int *sorted, int start, int end)
{
	int *copied;
	int	i;

	i = 0;
	while (start < end)
		copied[i++] = sorted[start++];
	return (copied);
}

int	*do_sorting(int *sorted, int end)
{
	int *left_array;
	int *right_array;

	if (end < 2)
		return sorted;
	left_array = copy_array(sorted, 0, end / 2);
	right_array = copy_array(sorted, end / 2 + 1, end);

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
	return (NULL);
//	merge();
}

void	merge_sort(int *a, int end)
{
	int	*sorted;
	int	i;

	i = -1;
	while (++i != end)
		sorted[i] = a[i];
	if (end < 2)
		return ;
	else
		do_sorting(sorted, end);
}

int	main(int ac, char *av[])
{
	int a[6] = {4, 1, 2, 9, 6, 12};

	merge_sort(a, 5);
//	printf();
//	printf("%d\n", 10 / 2);
//	printf("%d\n", 11 / 2);

	return (0);
}
