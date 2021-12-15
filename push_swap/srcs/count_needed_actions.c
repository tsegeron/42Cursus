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
