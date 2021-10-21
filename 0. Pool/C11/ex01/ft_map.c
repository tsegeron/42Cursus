/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:41:41 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/03 19:15:49 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*changed_tab;

	i = 0;
	changed_tab = malloc(sizeof(int) * (length));
	if (changed_tab == NULL)
		return ((void *)0);
	while (i != length)
	{
		changed_tab[i] = f(tab[i]);
		i++;
	}
	return (changed_tab);
}
