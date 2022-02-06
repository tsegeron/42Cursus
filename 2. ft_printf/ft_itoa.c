/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:13:33 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/06 19:33:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	ft_get_intlen(int num)
{
	int	i;

	i = 1;
	while (num / 10 != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

static char	*ft_getstr_min(int num, int end)
{
	char	*res;
	int		i;

	end++;
	i = end;
	res = (char *) malloc(end * sizeof(char) + 1);
	if (res)
	{
		res[0] = '-';
		while (end-- != 1)
		{
			res[end] = num % 10 * -1 + 48;
			num /= 10;
		}
		res[i] = '\0';
	}
	return (res);
}

static char	*ft_getstr_max(int num, int end)
{
	char	*res;
	int		i;

	i = end;
	res = (char *) malloc(end * sizeof(char) + 1);
	while (end-- != 0)
	{
		res[end] = num % 10 + 48;
		num /= 10;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_getstr_min(n, ft_get_intlen(n)));
	else
		return (ft_getstr_max(n, ft_get_intlen(n)));
}
