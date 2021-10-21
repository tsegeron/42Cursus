/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:12:33 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*changed;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	changed = ft_strdup(s);
	if (changed)
	{
		while (changed[i])
		{
			changed[i] = f(i, changed[i]);
			i++;
		}
	}
	return (changed);
}
