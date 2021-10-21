/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 05:19:24 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	rec_flags(char c, t_l *st)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		if (c == '-')
			st->minus = 1;
		else if (c == '+')
			st->plus = 1;
		else if (c == ' ')
			st->space = 1;
		else if (c == '#')
			st->mark = 1;
		else if (c == '0')
			st->zero = 1;
		return (1);
	}
	return (0);
}

static int	rec_width(char c, t_l *st)
{
	static int	width = 0;

	if (c >= '0' && c <= '9')
	{
		width = width * 10 + c - 48;
		return (1);
	}
	st->width = width;
	width = 0;
	return (0);
}

static int	rec_accur(char c, t_l *st)
{
	static int	accur = 0;

	if (c >= '0' && c <= '9')
	{
		accur = accur * 10 + c - 48;
		return (1);
	}
	st->accur = accur;
	accur = 0;
	return (0);
}

void	do_flags(const char *s, t_l *st)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)s;
	while (rec_flags(tmp[i], st))
		i++;
	while (rec_width(tmp[i], st))
		i++;
	if (tmp[i] == '.')
	{
		i++;
		while (rec_accur(tmp[i], st))
			i++;
		if (!st->accur && st->ct != 1 && st->ct != 3 && st->ct != 8)
			st->accur_xX = 1;
		if (!st->accur && (st->ct == 1 || st->ct == 3 || st->ct == 8))
			st->accur = 1;
	}
	do_cases(st);
}
