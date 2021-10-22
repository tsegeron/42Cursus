/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:14:27 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/22 20:04:24 by gernesto         ###   ########.fr       */
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

char	*ft_substr(char *s, int start, int len)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *) malloc (1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	joint = (char *) malloc ((ft_strlen(s1)
				+ ft_strlen(s2)) * sizeof(char) + 1);
	if (!joint)
		return (NULL);
	while (s1[++i] != '\0')
		joint[i] = s1[i];
	while (s2[j] != '\0')
		joint[i++] = s2[j++];
	joint[i] = '\0';
	free (s1);
	return (joint);
}

char	*ft_strchr(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i]);
		i++;
	}
	return (NULL);
}
