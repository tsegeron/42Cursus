/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 04:54:44 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/24 04:54:46 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strchr(char *s, char c)
{
	int		i;

	if (!s)
		return (NULL);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
