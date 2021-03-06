/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:27:31 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		if (c == 32)
			return (64);
		if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64)
			|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
			return (16);
		if ((c >= 'A' && c <= 'Z'))
			return (1);
		if (c >= 'a' && c <= 'z')
			return (2);
		if (c >= '0' && c <= '9')
			return (4);
	}
	return (0);
}
