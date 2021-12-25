/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:57:23 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/25 23:52:09 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/push_swap.h"

/*
void	print_stacks(t_s *s)
{
	t_list	*head_a = s->a;
	t_list	*head_b = s->b;
	t_list	*head_s = s->sorted;

	printf("\nTotal actions  :  %d\n", s->count_actions);
	printf("\nStuck a\n");
	while (s->a)
	{
		printf("%d ", s->a->num);
		s->a = s->a->next;
	}
	printf("\nStuck b\n");
	while (s->b)
	{
		printf("%d ", s->b->num);
		s->b = s->b->next;
	}
	printf("\nSorted\n");
	while (s->sorted)
	{
		printf("%d ", s->sorted->num);
		s->sorted = s->sorted->next;
	}
	s->a = head_a;
	s->b = head_b;
	s->sorted = head_s;
}
*/

static void	clear_all(t_s *s, char ***split)
{
	int	i;

	i = 0;
	ft_lstclear(&s->a);
	ft_lstclear(&s->b);
	ft_lstclear(&s->sorted);
	while ((*split)[i])
		free((*split)[i++]);
	free(*split);
}

void	do_1_method(t_s *s, int num)
{
	gt_set_statuses(s);
	move_to_b1(s, num);
	move_to_a(s, num);
	align_stack_a(s, num);
}

void	do_2_method(t_s *s, int num)
{
	move_to_b2(s, num);
	move_to_a(s, num);
	align_stack_a(s, num);
}

int	main(int ac, char *av[])
{
	char	**split;
	t_s		s;

	if (ac < 2)
		return (0);
	check_args(++av, &split);
	if (!fill_stacks(&s, &split))
		return ((int )write(2, "Error\n", 6));
	if (ft_lstsize(s.a) <= 350)
		do_1_method(&s, 0);
	else
		do_2_method(&s, 0);
	clear_all(&s, &split);
	return (0);
}
