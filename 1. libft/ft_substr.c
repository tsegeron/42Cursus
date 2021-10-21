/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:11:36 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (start > ft_strlen(s) - 1 || len == 0)
			len = 0;
		sub = (char *) malloc (len * sizeof(char) + 1);
		if (sub)
		{
			while (i != len && *s)
			{
				sub[i] = s[start];
				i++;
				start++;
			}
			sub[i] = '\0';
		}
		return (sub);
	}
	return (NULL);
}
