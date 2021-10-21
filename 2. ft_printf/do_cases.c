/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:29:36 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	do_cases(t_l *st)
{
	if (st->ct == 1)
		do_case_c(st);
	else if (st->ct == 2)
		do_case_s(va_arg(st->ap, char *), st);
	else if (st->ct == 3)
		do_case_p(ft_itoa_lhex(va_arg(st->ap, unsigned long long)), st);
	else if (st->ct == 4)
		do_case_di(ft_itoa(va_arg(st->ap, int)), st);
	else if (st->ct == 5)
		do_case_u(ft_itoa_uns(va_arg(st->ap, unsigned int)), st);
	else if (st->ct == 6)
		do_case_x(ft_itoa_lhex(va_arg(st->ap, unsigned int)), st);
	else if (st->ct == 7)
		do_case_x_up(ft_itoa_lhex(va_arg(st->ap, unsigned int)), st);
	else if (st->ct == 8)
		do_case_perc(st);
}
