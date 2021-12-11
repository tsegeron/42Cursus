/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:36:15 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/11 10:36:15 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	rra(sts *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = s->a;
	tmp2 = ft_lstlast(s->a);
	tmp3 = ft_lstprelast(s->a);
	if (ft_lstsize(s->a) > 1)
	{
		s->a = tmp2;
		tmp2->next = tmp1;
		tmp3->next = NULL;
		if (!q)
			write(1, "ra\n", 3);
	}
}

void	rrb(sts *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = s->b;
	tmp2 = ft_lstlast(s->b);
	tmp3 = ft_lstprelast(s->b);
	if (ft_lstsize(s->b) > 1)
	{
		s->b = tmp2;
		tmp2->next = tmp1;
		tmp3->next = NULL;
		if (!q)
			write(1, "ra\n", 3);
	}
}

void	rrr(sts *s, int q)
{
	rra(s, 1);
	rrb(s, 1);
	if (!q)
		write(1, "rr\n", 3);
}
