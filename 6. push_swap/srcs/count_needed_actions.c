/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_needed_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:31:20 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/16 18:38:45 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

/*
 * count_needed_actions_for_a
 * count_needed_actions_for_b
 * count_actions_to_pa
 */

/*
 * в стеке А нужно искать элемент с минимально
 * бóльший индексом, чем у того, что в стеке В
 */
static int	match_found(t_s *s, int a, int b)
{
	t_list	*ptr_a;
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
		if (ptr_a->i > b && ptr_a->i < minmax)
			minmax = ptr_a->i;
		ptr_a = ptr_a->next;
	}
	if (minmax == a)
		return (1);
	return (0);
}

/*
 * для нахождения модуля числа для подсчета
 * необходимых действий для push_a
 */
static int	module_of_(int num)
{
	if (num > 0)
		return (num);
	else
		return (0 - num);
}

/*
 * подсчет действий для push_a для каждого
 * элемента в стеке В
 */
void	count_actions_to_pa(t_s *s)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_b = s->b;
	while (ptr_b)
	{
		ptr_a = s->a;
		while (ptr_a)
		{
			if (match_found(s, ptr_a->i, ptr_b->i))
				break ;
			ptr_a = ptr_a->next;
		}
		ptr_b->actions_to_pa = module_of_(ptr_a->actions_num_a)
			+ module_of_(ptr_b->actions_num_b);
		ptr_b = ptr_b->next;
	}
}

/*
 * подсчет количества действий для каждого
 * элемента стека А, чтобы запушить на
 * начало стека
 */
void	count_needed_actions_for_a(t_s *s)
{
	t_list	*head_a;
	int		cur_pos;
	int		len_a;
	int		half_len_a;

	head_a = s->a;
	cur_pos = 0;
	len_a = ft_lstsize(s->a);
	if (!len_a)
		return ;
	half_len_a = len_a / 2;
	while (s->a)
	{
		if (cur_pos <= half_len_a)
			s->a->actions_num_a = cur_pos;
		else
			s->a->actions_num_a = (len_a - cur_pos) * -1;
		cur_pos++;
		s->a = s->a->next;
	}
	s->a = head_a;
}

/*
 * подсчет количества действий для каждого
 * элемента стека В, чтобы запушить на
 * начало стека
 */
void	count_needed_actions_for_b(t_s *s)
{
	t_list	*head_b;
	int		cur_pos;
	int		len_b;
	int		half_len_b;

	head_b = s->b;
	cur_pos = 0;
	len_b = ft_lstsize(s->b);
	if (!len_b)
		return ;
	half_len_b = len_b / 2;
	while (s->b)
	{
		if (cur_pos <= half_len_b)
			s->b->actions_num_b = cur_pos;
		else
			s->b->actions_num_b = (len_b - cur_pos) * -1;
		cur_pos++;
		s->b = s->b->next;
	}
	s->b = head_b;
}
