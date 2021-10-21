/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:28:25 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 20:28:27 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sort_int_tab(int tab1, int tab2)
{
	if (tab1 - tab2 < 0)
		return (-1);
	if (tab1 - tab2 == 0)
		return (0);
	else
		return (1);
}

int	check(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	if (tab[i] >= tab[length - 1])
	{
		while (i != length - 1)
		{
			if (f(tab[i], tab[i + 1]) >= 0)
				i++;
			else
				return (0);
		}
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	if (length <= 2)
		return (1);
	if (tab[i] <= tab[length - 1])
	{
		while (i != length - 1)
		{
			if (f(tab[i], tab[i + 1]) <= 0)
				i++;
			else
				return (0);
		}
	}
	else
	{
		if (check(tab, length, f) == 0)
			return (0);
	}
	return (1);
}
