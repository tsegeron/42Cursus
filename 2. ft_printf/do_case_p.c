/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_case_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:12:40 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/06 19:33:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	do_case_p(char *s, t_l *st)
{
	int	len;

	len = ft_strlen(s) + 2;
	if (st->minus)
	{
		ft_putstr_fd_c("0x", st, 1);
		ft_putstr_fd_c(s, st, 1);
		while (st->width > 0)
			ft_putchar_fd_c(' ', st, 1);
	}
	else
	{
		while (st->width > len)
			ft_putchar_fd_c(' ', st, 1);
		ft_putstr_fd_c("0x", st, 1);
		ft_putstr_fd_c(s, st, 1);
	}
	free (s);
}
