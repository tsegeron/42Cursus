/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:22:25 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/16 18:22:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

void	align_stack_a(t_s *s, int num)
{
	t_list	*ptr_a;

	count_needed_actions_for_a(s);
	ptr_a = s->a;
	while (ptr_a->i != 0)
		ptr_a = ptr_a->next;
	while (s->a->i != 0)
	{
		if (ptr_a->actions_num_a < 0)
			rra(s, num);
		else
			ra(s, num);
	}
}
