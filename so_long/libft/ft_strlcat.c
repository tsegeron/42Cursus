/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:58:03 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	indd;
	size_t	inds;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	indd = j;
	inds = 0;
	if (dstsize < j + 1)
		return (i + dstsize);
	if (dstsize > j + 1)
	{
		while (indd < dstsize - 1 && src[inds])
			dst[indd++] = src[inds++];
		dst[indd] = '\0';
	}
	return (i + j);
}
