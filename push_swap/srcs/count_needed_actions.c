#include "../hdrs/push_swap.h"

void	count_needed_actions_for_a(sts *s)
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
			s->a->actions_num_a = len_a - cur_pos;
		cur_pos++;
		s->a = s->a->next;
	}
	s->a = head_a;
}

void	count_needed_actions_for_b(sts *s)
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
			s->b->actions_num_b = len_b - cur_pos;
		cur_pos++;
		s->b = s->b->next;
	}
	s->b = head_b;
}

/*
 * в стеке А нужно искать элемент с минимально
 * бóльший индексом, чем у того, что в стаке В
 */
static int	match_found(sts *s, int a, int b)
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

void	count_actions_to_pa(sts *s)
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
		ptr_b->actions_to_pa = ptr_a->actions_num_a
			+ ptr_b->actions_num_b;
		ptr_b = ptr_b->next;
	}
}
