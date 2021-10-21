/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:22:33 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:44 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	zero_struct(t_l *st)
{
	st->minus = 0;
	st->plus = 0;
	st->space = 0;
	st->mark = 0;
	st->zero = 0;
	st->width = 0;
	st->accur = 0;
	st->accur_xX = 0;
}
