/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:06:58 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/20 00:21:25 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/push_swap.h"

/*
 *
 *
 *
 */
static int	free_lst_and_split(t_s *s, char ***split)
{
	int	i;

	i = 0;
	while ((*split)[i])
		free((*split)[i++]);
	free (*split);
	ft_lstclear(&s->a);
	return (0);
}

static int	fill_stack_a(t_s *s, char ***split)
{
	int	i;
	int	j;
	int	res;
	int	check_zero;

	i = 0;
	j = 0;
	while ((*split)[j])
	{
		check_zero = 0;
		res = ft_atoi((*split)[j++], &check_zero);
		if (!res && !check_zero)
		{
			free_lst_and_split(s, split);
			return (0);
		}
		ft_lstadd_back(&s->a, ft_lstnew(res, i++));
	}
	return (1);
}

static int	fill_stack_sorted(t_s *s, char ***split)
{
	t_list	*tmp;
	int		*sorted;
	int		i;

	tmp = s->a;
	sorted = (int *) malloc (sizeof(int) * ft_lstsize(s->a));
	if (!sorted)
		return (free_lst_and_split(s, split));
	i = 0;
	while (s->a)
	{
		sorted[i++] = s->a->num;
		s->a = s->a->next;
	}
	s->a = tmp;
	merge_sort(&sorted, 0, i - 1);
	i = -1;
	while (++i < ft_lstsize(s->a))
		ft_lstadd_back(&s->sorted, ft_lstnew(sorted[i], i));
	free (sorted);
	return (1);
}

static void	put_indexes(t_s *s)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = s->a;
	tmp2 = s->sorted;
	while (s->a)
	{
		s->sorted = tmp2;
		while (s->sorted)
		{
			if (s->a->num == s->sorted->num)
			{
				s->a->i = s->sorted->i;
				break ;
			}
			else
				s->sorted = s->sorted->next;
		}
		s->a = s->a->next;
	}
	s->a = tmp1;
	s->sorted = tmp2;
}

int	fill_stacks(t_s *s, char ***split)
{
	s->a = NULL;
	s->b = NULL;
	s->sorted = NULL;
	s->count_actions = 0;
	if (!fill_stack_a(s, split))
		return (0);
	if (!fill_stack_sorted(s, split))
		return (0);
	if (!check_for_duplicates(s))
		return (0);
	put_indexes(s);
	return (1);
}
