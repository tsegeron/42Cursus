/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:13:33 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/14 22:13:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_hex_len(int num)
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

//static char	*ft_getstr_min(int num, int end)
//{
//	char	*res;
//	int		i;
//
//	end++;
//	i = end;
//	res = (char *) malloc((end + 1) * sizeof(char));
//	if (res)
//	{
//		res[0] = '-';
//		while (end-- != 1)
//		{
//			res[end] = num % 16 * -1 + 30;
//			num /= 16;
//		}
//		res[i] = '\0';
//	}
//	return (res);
//}

static char	*get_str_hex(int num, int end)
{
	char	*res;
	char	*hex;
	int		i;

	hex = "0123456789ABCDEF";
	if (num < 0)
		end++;
	i = end;
	res = (char *) malloc((end + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (num < 10)
		res[0] = '-';
	while (end-- != 0 && res[end] != '-')
	{
		res[end] = hex[num % 16];
		num /= 16;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa_hex(int n)
{
	return (get_str_hex(n, get_hex_len(n)));
}
