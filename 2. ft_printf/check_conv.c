/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:02:15 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	check_flag(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0'
		|| c == '.' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	check_conv(const char *s, t_l *st)
{
	while (check_flag(*s))
		s++;
	if (*s == 'c')
		st->ct = 1;
	else if (*s == 's')
		st->ct = 2;
	else if (*s == 'p')
		st->ct = 3;
	else if (*s == 'd' || *s == 'i')
		st->ct = 4;
	else if (*s == 'u')
		st->ct = 5;
	else if (*s == 'x')
		st->ct = 6;
	else if (*s == 'X')
		st->ct = 7;
	else if (*s == '%')
		st->ct = 8;
	else
		st->ct = 0;
	if (st->ct != 0)
		return (1);
	return (0);
}
