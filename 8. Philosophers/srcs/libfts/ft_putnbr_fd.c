/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:12:44 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
		}
		a = (n % 10 + '0');
		n /= 10;
		if (n != 0)
			ft_putnbr_fd(n, fd);
		ft_putchar_fd(a, fd);
	}
}
