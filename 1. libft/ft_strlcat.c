/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:58:03 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/13 16:12:24 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	indd;
	size_t	inds;

	j = ft_strlen(dst);
	i = ft_strlen(src);
	indd = j;
	inds = 0;
	if (dstsize <= j + 1)
		return (i + dstsize);
	if (dstsize > j + 1)
	{
		while (indd < dstsize - 1 && src[inds])
			dst[indd++] = src[inds++];
		dst[indd] = '\0';
	}
	return (i + j);
}
