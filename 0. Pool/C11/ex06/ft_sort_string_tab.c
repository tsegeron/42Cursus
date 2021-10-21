/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:38:35 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 22:38:36 by gernesto         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int	m;
	int	n;

	m = 0;
	n = 1;
	while (tab[m] != NULL)
	{
		while (tab[n] != NULL)
		{
			if (ft_strcmp(tab[m], tab[n]) > 0)
				ft_swap(&tab[m], &tab[n]);
			n++;
		}
		m++;
		n = m + 1;
	}
}
