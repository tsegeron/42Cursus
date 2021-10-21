/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:14:27 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/22 01:17:00 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub;
	int		i;

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	joint = (char *) malloc ((ft_strlen(s1)
				+ ft_strlen(s2)) * sizeof(char) + 1);
	if (joint)
	{
		while (*s1)
		{
			joint[i] = *s1;
			s1++;
			i++;
		}
		while (*s2)
		{
			joint[i] = *s2;
			s2++;
			i++;
		}
		joint[i] = '\0';
	}
	return (joint);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *) malloc(ft_strlen(src) * sizeof(char) + 1);
	if (dup)
	{
		while (src[i] != '\0')
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
