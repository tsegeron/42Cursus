/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:43:48 by gernesto          #+#    #+#             */
/*   Updated: 2021/11/30 16:45:38 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int **sorted, int start, int end)
{
	int *copied;
	int	i;

	copied = (int *) malloc(sizeof(int) * (end - start));
	i = 0;
	while (start < end)
		copied[i++] = (*sorted)[start++];
	return (copied);
}



int	*do_sorting(int *sorted, int start, int end)
{
	int *left_array;
	int *right_array;

	if (end < 2)
		return (sorted);
	left_array = copy_array(&sorted, 0, end / 2);
	left_array = do_sorting(left_array, 0, end / 2);

//	start = end / 2 + 1;
	right_array = copy_array(&sorted, end / 2 + 1, end);
//	if (end % 2)
//		start = end / 2 + 1;
//	else
//		start = end / 2;
	right_array = do_sorting(right_array, 0, end / 2);

//	int q,w = 0; //check
//	while (q < end)
//		printf("left  : %d\n", left_array[q++]);
//	while (w < end)
//		printf("right : %d\n", right_array[w++]);


	merge(left_array, right_array, );

	return (sorted);
}

int	*merge_sort(int *a)
{
	int	*sorted;
	int size;

	size = sizeof(a)
	if (end > 2)
	{
		sorted = do_sorting(a, 0, end);
		return (sorted);
	}
	return (a);
}

int	main()
{
	int	a[6] = {4, 1, 2, 9, 6, 12};
//	int	*sorted;
//	int	i;
//
//	i = 0;
//	sorted = merge_sort(a);
//	while (i < 6)
//		printf("%d\n", a[i++]);
//	i = 0;
//	printf("\n");
//	while (i < 6)
//		printf("%d\n", sorted[i++]);
	printf("%lu\n", sizeof(a));



	return 0;
}