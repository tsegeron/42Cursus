/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_set_statuses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:07:11 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/24 21:43:06 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

/*
 * считает количество остающихся в стеке А
 * элементов, если начинать с определенного
 * элемента, который подается с gt_find_start
 */
static int	count_stay_a(t_s *s, t_list *tmp1)
{
	int		end;
	int		max;
	int		count;
	t_list	*tmp;

	tmp = s->a;
	end = s->a->i;
	max = s->a->i;
	count = 1;
	s->a = s->a->next;
	if (!s->a)
		s->a = tmp1;
	while (s->a->i != end)
	{
		if (s->a->i > max)
		{
			max = s->a->i;
			count++;
		}
		s->a = s->a->next;
		if (!s->a)
			s->a = tmp1;
	}
	s->a = tmp;
	return (count);
}

/*
 * находит элемент, начало с которого обеспечит
 * наибольшее кол-во элементов
 */
t_list	*gt_find_start(t_s *s)
{
	int		max;
	t_list	*ptr_max;
	t_list	*tmp1;

	tmp1 = s->a;
	max = 0;
	while (s->a)
	{
		s->a->stay_a = count_stay_a(s, tmp1);
		if (s->a->stay_a > max)
		{
			max = s->a->stay_a;
			ptr_max = s->a;
		}
		s->a = s->a->next;
	}
	s->a = tmp1;
	return (ptr_max);
}

/* Method #1
 * расставляет статусы для переноса в стек В
 * в порядке возрастания индекса в принципе
 * (не обязательно на 1)
 * 0 - оставить в А
 * 1 - перенос в В
 *
 * статусы ставятся исходя из start-элемента.
 * start-элемент выбирается в зависимости от
 * количества элементов, которые останутся в
 * stack_a(наибольшее количество - наш случай)
 */
void	gt_set_statuses(t_s *s)
{
	t_list	*start;
	int		i_end;
	int		i_tmp;

	start = gt_find_start(s);
	i_end = start->i;
	i_tmp = start->i;
	start->gt_status = 0;
	start = start->next;
	if (!start)
		start = s->a;
	while (start->i != i_end)
	{
		if (start->i > i_tmp)
		{
			i_tmp = start->i;
			start->gt_status = 0;
		}
		else
			start->gt_status = 1;
		start = start->next;
		if (!start)
			start = s->a;
	}
}
