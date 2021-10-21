/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:23:54 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 17:39:46 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr(int nb)
{
    char    a;

    if (nb == -2147483648)
    {
        write (1, "-2", 2);
        ft_putnbr (147483648);
    }
    else
    {
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
}

void	print_result(int a, int operator, int b)
{
	int	result;

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
