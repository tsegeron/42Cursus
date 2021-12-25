/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:21:27 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/25 22:56:58 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

/*
 * считает кол-во элементов в стеке А, чей статус
 * равен 1, то есть нужно перенести в стек Б
 */
static int	num_of_elements_to_be_moved(t_s *s)
{
	t_list	*head;
	int		count;

	count = 0;
	head = s->a;
	while (head)
	{
		if (head->gt_status)
			count++;
		head = head->next;
	}
	return (count);
}

/*
 * делает фейк sa, чтобы проверить изменилось ли
 * num_of_elements_to_be_moved, если после фейк sa
 * в стеке А останется больше элементов, то возвращает
 * 1 в move_to_b1, где делается sa
 */
static int	do_we_need_sa(t_s *s)
{
	int	before_sa;
	int	after_sa;

	before_sa = num_of_elements_to_be_moved(s);
	sa(s, 1, 1);
	gt_set_statuses(s);
	after_sa = num_of_elements_to_be_moved(s);
	sa(s, 1, 1);
	if (after_sa < before_sa)
		return (1);
	else
		gt_set_statuses(s);
	return (0);
}

/*
 * алгоритм переноса в стек Б для 1 алгоритма
 *
 * цикл крутится пока есть элементы со статусом 1
 * в стеке А
 */
void	move_to_b1(t_s *s, int num)
{
	while (num_of_elements_to_be_moved(s))
	{
		if (do_we_need_sa(s))
		{
			sa(s, num, 0);
			gt_set_statuses(s);
		}
		else if (s->a->gt_status)
			pb(s, num);
		else
			ra(s, num);
	}
}

/*
 * алгоритм переноса в стек Б для 2 алгоритма
 *
 * цикл крутится пока в стеке А не сотанутся
 * максимальное и минимальное значения
 *
 * значения выше медианы отправляются в низ
 * стека Б, ниже медианы - в топ
 */
void	move_to_b2(t_s *s, int num)
{
	int	size_a;
	int	mid;
	int	last;

	size_a = ft_lstsize(s->a);
	last = size_a - 1;
	mid = size_a / 2;
	while (size_a > 2)
	{
		if (s->a->i == 0 || s->a->i == last)
			ra(s, num);
		else
		{
			pb(s, num);
			if (s->b->i > mid)
				rb(s, num);
			size_a--;
		}
	}
	if (s->a->i < s->a->next->i)
		sa(s, num, 0);
}
