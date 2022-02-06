/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:41:08 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/06 19:33:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

void	ft_putstr_fd_c(char *s, t_l *st, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd_c(*(s++), st, fd);
}
