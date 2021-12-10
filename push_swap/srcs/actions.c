#include "../hdrs/push_swap.h"

void	sa(sts *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = s->a;
	tmp2 = s->a->next;
	if (ft_lstsize(s->a) > 1)
	{
		s->a = tmp2;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		if (!q)
			write(1, "sa\n", 3);
	}
}

void	sb(sts *s, int q)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = s->b;
	tmp2 = s->b->next;
	if (ft_lstsize(s->b) > 1)
	{
		s->b = tmp2;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		if (!q)
			write(1, "sb\n", 3);
	}
}

void	ss(sts *s, int q)
{
	sa(s, 1);
	sb(s, 1);
	write(1, "ss\n", 3);
}

void	pa(sts *s, int q)
{
	if (ft_lstsize(s->b) > 0)
	{
		ft_lstadd_front(&s->a, s->b);
//		ft_lstdelone(s->b);
		if (!q)
			write(1, "pa\n", 3);
	}

}

void	pb(sts *s, int q)
{
	if (ft_lstsize(s->a) > 0)
	{
		ft_lstadd_front(&s->b, s->a);
//		ft_lstdelone(s->b);
		if (!q)
			write(1, "pb\n", 3);
	}

}
