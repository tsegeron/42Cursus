/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:12:31 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		entry;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)&haystack[j]);
	while (haystack[j] != needle[i])
	{
		if (haystack[j] == '\0' || j >= len)
			return (NULL);
		j++;
	}
	entry = j;
	while (needle[i] == haystack[j] && needle[i] != '\0' && j < len)
	{
		i++;
		j++;
	}
	if (needle[i] == '\0')
		return ((char *)&haystack[entry]);
	return (NULL);
}
