/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:11:36 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/13 20:40:58 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/push_swap.h"

//static size_t	ft_strlen(const char *str)
//{
//	int	i;
//
//	i = 0;
//	while (str[i])
//		i++;
//	return (i);
//}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1 || len == 0)
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
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
