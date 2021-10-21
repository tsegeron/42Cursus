/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:12:34 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joint;
	unsigned int	i;

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
