/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:23:54 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 21:53:21 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(long long int nb)
{
	char	a;

	if (nb < 0)
	{
		nb = -nb;
		write (1, "-", 1);
	}
	a = (nb % 10 + '0');
	nb = nb / 10;
	if (nb != 0)
		ft_putnbr(nb);
	write (1, &a, 1);
}

void	print_result(long long int a, int operator, long long int b)
{
	long long int	result;

	if (operator == 1)
		result = a + b;
	if (operator == 2)
		result = a - b;
	if (operator == 3)
		result = a / b;
	if (operator == 4)
		result = a * b;
	if (operator == 5)
		result = a % b;
	ft_putnbr(result);
	write (1, "\n", 1);
}
