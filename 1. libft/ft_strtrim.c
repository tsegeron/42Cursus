/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:12:09 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_start(const char *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		j = 0;
		i++;
	}
	return (i);
}

static int	ft_check_end(const char *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		while (set[j])
		{
			if (str[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0')
			break ;
		j = 0;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	int				start;
	int				end;
	unsigned int	i;

	if (s1)
	{
		i = 0;
		start = ft_check_start(s1, set);
		end = ft_check_end(s1, set);
		if (end <= 0)
			start = 1;
		trimmed = (char *) malloc ((end - start + 1) * sizeof(char) + 1);
		if (!trimmed)
			return (NULL);
		while (start <= end)
			trimmed[i++] = s1[start++];
		trimmed[i] = '\0';
		return (trimmed);
	}
	return (NULL);
}
