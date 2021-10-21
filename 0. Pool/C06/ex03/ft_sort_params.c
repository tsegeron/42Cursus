/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:39:50 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/29 19:41:58 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int a, char **b)
{
	int	m;
	int	n;

	m = 1;
	n = 1;
	while (m != a)
	{
		while (n++, n != a)
		{
			if (ft_strcmp(b[m], b[n]) > 0)
				ft_swap(&b[m], &b[n]);
		}
		m++;
		n = m + 1;
	}
	m = 1;
	while (m != a)
	{
		ft_putstr(b[m]);
		write (1, "\n", 1);
		m++;
	}
	return (0);
}
