/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 23:26:10 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/28 23:26:13 by gernesto         ###   ########.fr       */
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

	m = 1;
	while (m != a)
	{
		ft_putstr(b[m]);
		write (1, "\n", 1);
		m++;
	}
	return (0);
}
