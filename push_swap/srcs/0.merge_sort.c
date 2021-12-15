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

#include "../hdrs/push_swap.h"

void	merge(int a[], int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;
	int left[mid - start + 1];
	int right[end - mid];

	i = -1;
	j = -1;

	while (++i < mid - start + 1)
		left[i] = a[start + i];
	while (++j < end - mid)
		right[j] = a[mid + j + 1];

	i = 0;
	j = 0;
	k = start;
	while (i < mid - start + 1 && j < end - mid)
	{
		if (left[i] <= right[j])
			a[k] = left[i++];
		else
			a[k] = right[j++];
		k++;
	}
	while (i < mid - start + 1)
		a[k++] = left[i++];
	while (j < end - mid)
		a[k++] = right[j++];
}

void	merge_sort(int a[], size_t start, size_t end)
{
	int	mid;

	if (start < end)
	{
		mid = start + (end - start) / 2;
		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}
/*
int	main(int ac, char *av[])
{
	int a[] = {4, 1, 2, 9, 6, 12};
	int b[] = {4, 1, 2, 9, 6, 12, 14, 32, 48, 52, 7, 11};
	size_t	int_count;
	size_t	int_countb;

	int_count = sizeof (a) / sizeof (a[0]);
	int_countb = sizeof (b) / sizeof (b[0]);

	//	printf("ints num  :  %lu\n",int_count);
	printf("ints num  :  %lu\n",int_countb);

	//	merge_sort(a, 0, int_count);
	printf("\nGiven\n");
	for (int i = 0; i < int_countb; i++)
		printf("%d ", b[i]);
	merge_sort(b, 0, int_countb - 1);

	//	printf();
	printf("\nSorted\n");
	for (int i = 0; i < int_countb; i++)
		printf("%d ", b[i]);

	return (0);
}
 */