/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:25:11 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/19 18:36:18 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	check_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *string, ...)
{
	t_l	st;

	st.tmp = (char *)string;
	st.count = 0;
	va_start(st.ap, string);
	st.i = 0;
	while (st.tmp[st.i])
	{
		st.ct = 0;
		if (st.tmp[st.i] == '%' && check_conv(string + ++st.i, &st))
		{
			zero_struct(&st);
			do_flags(string + st.i, &st);
			while (!check_char(st.tmp[st.i]))
				st.i++;
		}
		else
			ft_putchar_fd_c(st.tmp[st.i], &st, 1);
		st.i++;
	}
	va_end(st.ap);
	return (st.count);
}
