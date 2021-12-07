/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:00:10 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/13 21:51:02 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/libft.h"

static int	ft_substrs_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static size_t	ft_strlen_up(char const *str, int start, char c)
{
	size_t	i;

	i = 0;
	while (str[start] == c)
		start++;
	while (str[start] != c && str[start++] != '\0')
		i++;
	return (i);
}

char	**ft_get_array(char const *s, char c, int count)
{
	char	**array;
	char	*string;
	size_t	lenstr;
	int		i;
	int		a;

	i = 0;
	a = 0;
	array = (char **) malloc ((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array[count] = NULL;
	if (count == 0)
		return (array);
	while (count-- != 0)
	{
		while (s[i] == c)
			i++;
		lenstr = ft_strlen_up(s, i, c);
		string = ft_substr(s, i, lenstr);
		array[a++] = ft_strdup(string);
		free(string);
		i += lenstr;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = ft_substrs_count(s, c);
	array = ft_get_array(s, c, count);
	while (i < count - 1)
	{
		if (array[i] == NULL)
			break ;
		i++;
	}
	if (i < count - 1)
	{
		i = 0;
		while (i != count - 1)
			free (array[i++]);
		free(array);
		return (NULL);
	}
	return (array);
}
