/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:41:13 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/11 10:19:16 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/pipex.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		*ptr;
	size_t	i;

	i = 0;
	ptr = (int *)malloc(count * size);
	if (ptr)
		while (i != count)
			ptr[i++] = 0;
	return (ptr);
}
