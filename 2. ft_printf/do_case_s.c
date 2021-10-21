/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_case_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:26:30 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	do_case_s(char *s, t_l *st)
{
	int	end;

	if (!s)
		s = "(null)";
	end = ft_strlen(s);
	if (st->accur < end && st->accur)
		end = st->accur;
	if (st->accur < end && st->accur_xX)
		end = st->accur;
	if (st->minus)
	{
		while (end--)
			ft_putchar_fd_c(*s++, st, 1);
		while (st->width > 0)
			ft_putchar_fd_c(' ', st, 1);
	}
	else
	{
		while (st->width > end)
			ft_putchar_fd_c(' ', st, 1);
		while (end--)
			ft_putchar_fd_c(*s++, st, 1);
	}
}
