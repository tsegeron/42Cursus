#include "../hdrs/push_swap.h"

static int	do_we_need_sa(sts *s)
{
	int	before_sa;
	int	after_sa;

	before_sa = s->a->stay_a;
	sa(s, 1);
	gt_set_statuses(s);
	after_sa = s->a->stay_a;
//	printf("before >> %d\n", before_sa);
//	printf("after >> %d\n", after_sa);
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

void	do_magic(sts *s)
{
	int size_a;
//	t_list *tmp1;

	size_a = ft_lstsize(s->a);
//	tmp1 = s->a;

// algorithm to move from A to B
	while (size_a)
	{
//		if (s->a->next && s->a->i > s->a->next->i)
		if (do_we_need_sa(s))
		{
			sa(s, 0);
			gt_set_statuses(s);
		}
		else if (s->a->gt_status)
			pb(s, 0);
		else
			ra(s, 0);
		size_a--;
	}
	count_needed_actions_for_a(s);
// algorithm to move from A to B
//	while (s->b)
//	{
//
//	}
}
