/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:43:48 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/25 22:43:57 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

static void	stuff(t_for_merge *m, size_t start, size_t mid, size_t end)
{
	m->left = (int *) malloc(sizeof(int) * (mid - start + 1));
	if (!m->left)
		exit((int )write(2, "Malloc error\n", 13));
	m->right = (int *) malloc(sizeof(int) * (end - mid));
	if (!m->right)
		exit((int )write(2, "Malloc error\n", 13));
	m->i = -1;
	m->j = -1;
}

static void	merge(int **a, size_t start, size_t mid, size_t end)
{
	t_for_merge	m;

	stuff(&m, start, mid, end);
	while (++m.i < mid - start + 1)
		m.left[m.i] = (*a)[start + m.i];
	while (++m.j < end - mid)
		m.right[m.j] = (*a)[mid + m.j + 1];
	m.i = 0;
	m.j = 0;
	m.k = start;
	while (m.i < mid - start + 1 && m.j < end - mid)
	{
		if (m.left[m.i] <= m.right[m.j])
			(*a)[m.k] = m.left[m.i++];
		else
			(*a)[m.k] = m.right[m.j++];
		m.k++;
	}
	while (m.i < mid - start + 1)
		(*a)[m.k++] = m.left[m.i++];
	free(m.left);
	while (m.j < end - mid)
		(*a)[m.k++] = m.right[m.j++];
	free(m.right);
}

void	merge_sort(int **a, size_t start, size_t end)
{
	size_t	mid;

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