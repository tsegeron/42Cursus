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
		if (ptr_a->i > b)
		ptr_a = ptr_a->next;
	}
	return (0);
}

int		find_matching_index_elem(sts *s)
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
//			if (!ptr_a)
//				ptr_a = s->a;
		}
		ptr_b->actions_to_pa = ptr_a->actions_num_a
				+ ptr_b->actions_num_b;
		ptr_b = ptr_b->next;
	}
	return (1);
}

void	count_actions_to_pa(sts *s)
{

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

// algorithm to move from A to B
//	while (s->b)
//	{
//
//	}
}
