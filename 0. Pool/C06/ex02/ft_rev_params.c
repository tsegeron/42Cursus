/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 23:40:06 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/28 23:40:39 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

	m = a - 1;
	while (m != 0)
	{
		ft_putstr(b[m]);
		write (1, "\n", 1);
		m--;
	}
	return (0);
}
