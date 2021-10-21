/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:17:23 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printft.h"

static int	get_hex_len(unsigned int num)
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

static char	*get_str_hex(unsigned int num, int end)
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

char	*ft_itoa_hex(unsigned int n)
{
	char	*hex_res;

	hex_res = get_str_hex(n, get_hex_len(n));
	return (hex_res);
}
