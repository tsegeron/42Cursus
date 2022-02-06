/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_case_x_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:26:04 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/06 19:33:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static void	do_else_else(char *s, t_l *st, int len)
{
	if (st->zero && st->mark && s[0] != '0')
		ft_putstr_fd_c("0X", st, 1);
	while (st->width > len)
	{
		if (st->zero)
			ft_putchar_fd_c('0', st, 1);
		else
			ft_putchar_fd_c(' ', st, 1);
	}
	if (!st->zero && st->mark && s[0] != '0')
		ft_putstr_fd_c("0X", st, 1);
	while (len--)
		ft_putchar_fd_c(ft_toupper(*s++), st, 1);
}

static void	do_else_if(char *s, t_l *st, int len)
{
	if (st->accur >= len && !st->accur_xX)
	{
		if (st->mark && s[0] != '0')
			ft_putstr_fd_c("0X", st, 1);
		while (st->width > st->accur)
			ft_putchar_fd_c(' ', st, 1);
	}
	else
	{
		if (!st->accur && st->accur_xX)
			while (st->width > len)
				ft_putchar_fd_c(' ', st, 1);
		else
			while (st->width > len)
				ft_putchar_fd_c(' ', st, 1);
		if (st->mark && s[0] != '0')
			ft_putstr_fd_c("0X", st, 1);
	}
	while (st->accur-- > len)
		ft_putchar_fd_c('0', st, 1);
	while (len--)
		ft_putchar_fd_c(ft_toupper(*s++), st, 1);
}

static void	do_else(char *s, t_l *st, int len)
{
	if (st->accur)
		do_else_if(s, st, len);
	else
		do_else_else(s, st, len);
}

static void	do_if(char *s, t_l *st, int len)
{
	if (st->mark && s[0] != '0')
		ft_putstr_fd_c("0X", st, 1);
	while (st->accur-- > len)
		ft_putchar_fd_c('0', st, 1);
	while (len--)
	{
		if (!st->accur && s[0] == 0)
			ft_putchar_fd_c(' ', st, 1);
		else
			ft_putchar_fd_c(ft_toupper(*s++), st, 1);
	}
	while (st->width > 0)
		ft_putchar_fd_c(' ', st, 1);
}

void	do_case_x_up(char *s, t_l *st)
{
	int		len;

	len = ft_strlen(s);
	if (*s == '0' && st->accur_xX && !st->accur)
	{
		while (st->width > 0)
			ft_putchar_fd_c(' ', st, 1);
		free (s);
		return ;
	}
	if (st->minus)
		do_if(s, st, len);
	else
		do_else(s, st, len);
	free (s);
}
