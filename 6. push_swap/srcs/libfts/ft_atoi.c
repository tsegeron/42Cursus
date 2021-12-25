/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:17:04 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/19 23:53:30 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/push_swap.h"

static int	ft_isspace(char c, int *m)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == '+')
		return (1);
	else if (c == '-')
	{
		*m = -1 * *m;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str, int *check_zero)
{
	unsigned long long	res;
	int					m;
	int					i;

	res = 0;
	m = 1;
	i = 0;
	while (ft_isspace(str[i], &m))
		i++;
	if ((str[i] < '0') || (str[i] > '9'))
		return (0);
	while ((str[i] > 47) && (str[i] < 58))
	{
		res = res * 10 + str[i++] - 48;
		*check_zero = 1;
	}
	if ((res > 2147483647 && m > 0) || (res > 2147483648 && m < 0) \
	|| (((str[i] < '0') || (str[i] > '9')) && str[i] != ' ' && str[i]))
	{
		*check_zero = 0;
		return (0);
	}
	return ((int)res * m);
}
