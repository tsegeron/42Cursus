/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:25:39 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/21 19:30:20 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	ra(t_s *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (ft_lstsize(s->a) > 1)
	{
		tmp1 = s->a;
		tmp2 = s->a->next;
		tmp3 = ft_lstlast(s->a);
		s->a = tmp2;
		tmp3->next = tmp1;
		tmp1->next = NULL;
		if (!q)
			write(1, "ra\n", 3);
		s->count_actions++;
	}
}

void	rb(t_s *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (ft_lstsize(s->b) > 1)
	{
		tmp1 = s->b;
		tmp2 = s->b->next;
		tmp3 = ft_lstlast(s->b);
		s->b = tmp2;
		tmp3->next = tmp1;
		tmp1->next = NULL;
		if (!q)
			write(1, "rb\n", 3);
		s->count_actions++;
	}
}

void	rr(t_s *s, int q)
{
	ra(s, 1);
	rb(s, 1);
	if (!q)
		write(1, "rr\n", 3);
	s->count_actions++;
}

/*
void	ra(t_s *s, int q)
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
		tmp2->next = tmp1->next;
		tmp3->next = tmp1;
		tmp1->next = NULL;
		if (!q)
			write(1, "ra\n", 3);
	}
}
 */