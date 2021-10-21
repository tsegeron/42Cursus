/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:30:34 by gernesto          #+#    #+#             */
/*   Updated: 2021/07/27 17:31:51 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	a;

	if (nb == -2147483648)
	{
		write (1, "2", 1);
		ft_putnbr (147483648);
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		a = (nb % 10 + '0');
		nb = nb / 10;
		if (nb != 0)
			ft_putnbr(nb);
		ft_putchar(a);
	}
}
