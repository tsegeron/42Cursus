/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:17:14 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/19 21:17:14 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	get_lhex_len(unsigned long long num)
{
	int	i;

	i = 1;
	while (num / 16 != 0)
	{
		i++;
		num /= 16;
	}
	return (i);
}

static char	*get_str_lhex(unsigned long long num, int end)
{
	char	*res;
	char	*hex;

	hex = "0123456789abcdef";
	res = (char *) malloc((end + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[end] = '\0';
	while (end-- != 0)
	{
		res[end] = hex[num % 16];
		num /= 16;
	}
	return (res);
}

char	*ft_itoa_lhex(unsigned long long n)
{
	char	*hex_res;

	hex_res = get_str_lhex(n, get_lhex_len(n));
	return (hex_res);
}
