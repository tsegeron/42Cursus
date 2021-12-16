#include "../hdrs/push_swap.h"

static int	do_we_need_sa(sts *s)
{
	int	before_sa;
	int	after_sa;

	before_sa = s->a->stay_a;
	sa(s, 1);
	gt_set_statuses(s);
	after_sa = s->a->stay_a;
	if (after_sa > before_sa)
	{
		sa(s, 1);
		return (1);
	}
	else
	{
		sa(s, 1);
		gt_set_statuses(s);
	}
	return (0);
}

static int	num_of_elements_to_be_moved(sts *s)
{
	t_list	*head_a;
	int		count;

	count = 0;
	head_a = s->a;
	while (s->a)
	{
		if (s->a->gt_status)
			count++;
		s->a = s->a->next;
	}
	s->a = head_a;
	return (count);
}



void	do_magic(sts *s)
{
//	t_list *tmp1;

//	tmp1 = s->a;

// algorithm to move from A to B
	while (num_of_elements_to_be_moved(s))
	{
		if (do_we_need_sa(s))
		{
			sa(s, 0);
			gt_set_statuses(s);
		}
		else if (s->a->gt_status)
			pb(s, 0);
		else
			ra(s, 0);
	}
	count_needed_actions_for_a(s);
	count_needed_actions_for_b(s);
	count_actions_to_pa(s);
	find_best_elem_to_pa(s);
// algorithm to move from A to B
//	while (s->b)
//	{
//
//	}
}
