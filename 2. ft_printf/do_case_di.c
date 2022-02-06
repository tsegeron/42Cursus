/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_case_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:26:33 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/06 19:33:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static void	do_else_wnm(char *tmp, t_l *st, int len)
{
	char	*tmp2;

	tmp2 = tmp;
	if (*tmp2 == '-' && st->zero)
		ft_putchar_fd_c(*tmp++, st, 1);
	if (*tmp2 != '-' && st->plus && st->zero)
		ft_putchar_fd_c('+', st, 1);
	len = ft_strlen(tmp);
	while (st->width > len)
	{
		if (st->zero)
			ft_putchar_fd_c('0', st, 1);
		else
			ft_putchar_fd_c(' ', st, 1);
	}
	if (*tmp2 == '-' && !st->zero)
		ft_putchar_fd_c(*tmp++, st, 1);
	if (*tmp2 != '-' && st->plus && !st->zero)
		ft_putchar_fd_c('+', st, 1);
	while (*tmp)
		ft_putchar_fd_c(*tmp++, st, 1);
}

static void	when_no_minus(char *tmp, t_l *st, int len)
{
	if (st->accur)
	{
		if (st->plus || '-' == tmp[0])
			st->width--;
		if (st->accur > len)
			while (st->width > st->accur)
				ft_putchar_fd_c(' ', st, 1);
		else
			while (st->width > len)
				ft_putchar_fd_c(' ', st, 1);
		if ('-' == tmp[0])
			ft_putchar_fd_c(*tmp++, st, 1);
		else if (st->plus)
			ft_putchar_fd_c('+', st, 1);
		while (st->accur-- > len)
			ft_putchar_fd_c('0', st, 1);
		while (len--)
			ft_putchar_fd_c(*tmp++, st, 1);
	}
	else
		do_else_wnm(tmp, st, len);
}

static void	when_minus(char *tmp, t_l *st, int len)
{
	if (tmp[0] == '-')
		ft_putchar_fd_c(*tmp++, st, 1);
	else if (st->plus)
		ft_putchar_fd_c('+', st, 1);
	while (st->accur-- > len)
		ft_putchar_fd_c('0', st, 1);
	while (len--)
		ft_putchar_fd_c(*tmp++, st, 1);
	while (st->width > 0)
		ft_putchar_fd_c(' ', st, 1);
}

void	do_case_di(char *s, t_l *st)
{
	int		len;

	if ('0' == *s && st->accur_xX && !st->accur)
	{
		while (st->width > 0)
			ft_putchar_fd_c(' ', st, 1);
		free (s);
		return ;
	}
	len = ft_strlen(s);
	if ('-' == *s)
		len -= 1;
	if (st->space && !st->plus && '-' != *s)
		ft_putchar_fd_c(' ', st, 1);
	if (st->minus)
		when_minus(s, st, len);
	else
		when_no_minus(s, st, len);
	free (s);
}
