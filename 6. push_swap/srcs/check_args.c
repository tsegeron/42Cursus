/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:07:45 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/16 22:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

int	check_for_duplicates(t_s *s)
{
	t_list	*ptr_sorted;
	int		tmp;

	ptr_sorted = s->sorted;
	tmp = ptr_sorted->num;
	ptr_sorted = ptr_sorted->next;
	while (ptr_sorted)
	{
		if (ptr_sorted->num == tmp)
			return (0);
		tmp = ptr_sorted->num;
		ptr_sorted = ptr_sorted->next;
	}
	return (1);
}

void	check_args(char *av[], char ***split)
{
	char	*joint;

	joint = NULL;
	while (*av)
		joint = ft_strjoin(joint, *av++);
	*split = ft_split(joint, ' ');
	free(joint);
}
