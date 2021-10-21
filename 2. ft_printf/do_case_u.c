/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:44:43 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static void	do_if_st_accur(char *s, t_l *st, int len)
{
	if (st->accur > len)
	{
		while (st->width > st->accur)
			ft_putchar_fd_c(' ', st, 1);
		while (st->accur-- > len)
			ft_putchar_fd_c('0', st, 1);
	}
	else
		while (st->width > len)
			ft_putchar_fd_c(' ', st, 1);
	while (len--)
		ft_putchar_fd_c(*s++, st, 1);
}

static void	do_else(char *s, t_l *st, int len)
{
	if (st->accur)
		do_if_st_accur(s, st, len);
	else
	{
		while (st->width > len)
		{
			if (st->zero)
				ft_putchar_fd_c('0', st, 1);
			else
				ft_putchar_fd_c(' ', st, 1);
		}
		while (len--)
			ft_putchar_fd_c(*s++, st, 1);
	}
}

void	do_case_u(char *s, t_l *st)
{
	int		len;
	char	*tmp;

	if (*s == '0' && st->accur_xX && !st->accur)
	{
		while (st->width > 0)
			ft_putchar_fd_c(' ', st, 1);
		free (s);
		return ;
	}
	tmp = s;
	len = ft_strlen(s);
	if (st->minus)
	{
		while (st->accur-- > len)
			ft_putchar_fd_c('0', st, 1);
		while (len--)
			ft_putchar_fd_c(*tmp++, st, 1);
		while (st->width > 0)
			ft_putchar_fd_c(' ', st, 1);
	}
	else
		do_else(s, st, len);
	free (s);
}
