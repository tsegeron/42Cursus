/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:20:33 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/25 22:17:31 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

static t_list	*find_pair(t_s *s, int b)
{
	t_list	*ptr_a;
	t_list	*ptr_pair;
	int		minmax;

	ptr_a = s->a;
	minmax = ptr_a->i;
	while (ptr_a)
	{
		if (ptr_a->i > minmax)
			minmax = ptr_a->i;
		ptr_a = ptr_a->next;
	}
	ptr_a = s->a;
	while (ptr_a)
	{
		if (ptr_a->i > b && ptr_a->i <= minmax)
		{
			minmax = ptr_a->i;
			ptr_pair = ptr_a;
		}
		ptr_a = ptr_a->next;
	}
	return (ptr_pair);
}

static t_list	*find_best_elem_to_pa(t_s *s)
{
	t_list	*tmp_b;
	t_list	*ret_b;
	int		acts;

	tmp_b = s->b;
	acts = s->b->actions_to_pa;
	ret_b = s->b;
	while (s->b)
	{
		if (s->b->actions_to_pa < acts)
		{
			acts = s->b->actions_to_pa;
			ret_b = s->b;
		}
		s->b = s->b->next;
	}
	s->b = tmp_b;
	return (ret_b);
}

static void	prepare_a_for_pa(t_s *s, int i_b, int num)
{
	t_list	*ptr_pair;

	ptr_pair = find_pair(s, i_b);
	while (s->a->i != ptr_pair->i)
	{
		if (ptr_pair->actions_num_a < 0)
			rra(s, num);
		else
			ra(s, num);
	}
}

void	move_to_a(t_s *s, int num)
{
	t_list	*ptr_pa;

	while (s->b)
	{
		count_needed_actions_for_a(s);
		count_needed_actions_for_b(s);
		count_actions_to_pa(s);
		ptr_pa = find_best_elem_to_pa(s);
		while (s->b->i != ptr_pa->i)
		{
			if (ptr_pa->actions_num_b < 0)
				rrb(s, num);
			else
				rb(s, num);
		}
		prepare_a_for_pa(s, s->b->i, num);
		pa(s, num);
	}
}
