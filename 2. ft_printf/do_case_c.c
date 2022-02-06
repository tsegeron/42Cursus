/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_case_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:26:22 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/06 19:33:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	do_case_c(t_l *st)
{
	if (st->minus)
	{
		ft_putchar_fd_c(va_arg(st->ap, int), st, 1);
		while (st->width > 0)
			ft_putchar_fd_c(' ', st, 1);
	}
	else
	{
		while (st->width > 1)
			ft_putchar_fd_c(' ', st, 1);
		ft_putchar_fd_c(va_arg(st->ap, int), st, 1);
	}
}
