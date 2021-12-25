/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:57:28 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/23 02:32:00 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	sa(t_s *s, int q, int w)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_lstsize(s->a) > 1)
	{
		tmp1 = s->a;
		tmp2 = s->a->next;
		s->a = tmp2;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		if (!q)
			write(1, "sa\n", 3);
		if (!w)
			s->count_actions++;
	}
}

void	sb(t_s *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_lstsize(s->b) > 1)
	{
		tmp1 = s->b;
		tmp2 = s->b->next;
		s->b = tmp2;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		if (!q)
			write(1, "sb\n", 3);
		s->count_actions++;
	}
}

void	ss(t_s *s, int q)
{
	sa(s, 1, 1);
	sb(s, 1);
	if (!q)
		write(1, "ss\n", 3);
	s->count_actions++;
}

void	pa(t_s *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = s->b;
	tmp2 = s->a;
	if (ft_lstsize(s->b) > 0)
	{
		s->b = tmp1->next;
		s->a = tmp1;
		tmp1->next = tmp2;
		if (!q)
			write(1, "pa\n", 3);
		s->count_actions++;
	}
}

void	pb(t_s *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = s->a;
	tmp2 = s->b;
	if (ft_lstsize(s->a) > 0)
	{
		s->a = tmp1->next;
		s->b = tmp1;
		tmp1->next = tmp2;
		if (!q)
			write(1, "pb\n", 3);
		s->count_actions++;
	}
}
