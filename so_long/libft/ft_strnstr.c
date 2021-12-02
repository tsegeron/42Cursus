/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:12:31 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/13 21:27:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	char	*tmp1;
	char	*tmp2;
	size_t	i;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	if (*s2 == '\0')
		return (s1);
	while (*s1 && len)
	{
		tmp1 = s1;
		tmp2 = s2;
		i = len;
		while (*tmp1 == *tmp2 && i-- && *tmp2 && *(tmp2++))
			tmp1++;
		if (*tmp2 == '\0' || (!i && *tmp1 == *tmp2))
			return (s1);
		s1++;
		len--;
	}
	return (NULL);
}
