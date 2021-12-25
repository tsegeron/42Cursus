/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:36:15 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/21 19:30:20 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	rra(t_s *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (ft_lstsize(s->a) > 1)
	{
		tmp1 = s->a;
		tmp2 = ft_lstlast(s->a);
		tmp3 = ft_lstprelast(s->a);
		s->a = tmp2;
		tmp2->next = tmp1;
		tmp3->next = NULL;
		if (!q)
			write(1, "rra\n", 4);
		s->count_actions++;
	}
}

void	rrb(t_s *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (ft_lstsize(s->b) > 1)
	{
		tmp1 = s->b;
		tmp2 = ft_lstlast(s->b);
		tmp3 = ft_lstprelast(s->b);
		s->b = tmp2;
		tmp2->next = tmp1;
		tmp3->next = NULL;
		if (!q)
			write(1, "rrb\n", 4);
		s->count_actions++;
	}
}

void	rrr(t_s *s, int q)
{
	rra(s, 1);
	rrb(s, 1);
	if (!q)
		write(1, "rrr\n", 4);
	s->count_actions++;
}
