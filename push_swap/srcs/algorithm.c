#include "../hdrs/push_swap.h"

void	do_magic(sts *s)
{
	int		size_a;
	t_list	*tmp1;

	size_a = ft_lstsize(s->a);
	tmp1 = s->a;
	while (size_a)
	{
		if (s->a->status)
			pb(s, 0);
		else
			ra(s, 0);
		size_a--;
	}



	s->a = tmp1;










//	if (s->a->i > s->a->next->i)
//		sa(s, 1);
//	sb(s, 1);
//	pa(s, 1);

//	ra(s, 1);
//	pb(s, 1);
//	ra(s, 1);
//	ra(s, 1);
//	pb(s, 1);
//	pb(s, 1);
//	ra(s, 1);
//	pa(s, 1);
//	ra(s, 1);
//	rb(s, 1);
//	pa(s, 1);
//	ra(s, 1);
//	ra(s, 1);
//	pa(s, 1);
//	rra(s, 1);

//	ra(s, 1);
//	pb(s, 1);
//	pb(s, 1);
//	pa(s, 1);
//	ra(s, 1);

//	rra(s, 1);
//	rra(s, 1);
//	pa(s, 1);


//	ra(s, 1);
//	ra(s, 1);
//	ra(s, 1);
//	pb(s, 1);
//	rra(s, 1);
//	rb(s, 1);
//	rra(s, 1);
//	rrb(s, 1);

}
/*
 * 1. найти наименьшее число
 * 2. обозначить статус переноса для последующих
 * по алгоритму возрастания индекса относительно предыдущего
 * числа, при этом смотря на число шагом наперед;
 * если оно меньше предыдущего, чей статус мы проверяем,
 * то статус предыдущего автоматически = 1 (перенос),
 * и так до конца #ДОРАБОТАТЬ
 * 3.
 *
 */