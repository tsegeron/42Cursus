/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:58:56 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 22:58:57 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	m;
	int	n;

	m = 0;
	n = 1;
	while (tab[m] != NULL)
	{
		while (tab[n] != NULL)
		{
			if (cmp(tab[m], tab[n]) > 0)
				ft_swap(&tab[m], &tab[n]);
			n++;
		}
		m++;
		n = m + 1;
	}
}
