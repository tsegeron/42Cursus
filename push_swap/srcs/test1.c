#include "../hdrs/push_swap.h"

static void	fill_stack_a(sts *s, char *av[])
{
	int	i;
	int	check_zero;

	i = 0;
	s->len_a = 0;
	while (*av)
	{
		check_zero = 0;
		ft_lstadd_back(&s->a, ft_lstnew(ft_atoi(*av++, &check_zero), i++));
		s->len_a++;
		if (!s->a->num && !check_zero)
		{
			free (s->a); // дописать функцию по очистке всего списка
			return ;
		}
	}
}

static void	fill_stack_sorted(sts *s, int ac)
{
	t_list	*tmp;
	int	so[ac - 1];
	int	i;

	i = 0;
	tmp = s->a;

	while (s->a)
	{
		so[i++] = s->a->num;
		s->a = s->a->next;
	}
	s->a = tmp;
	merge_sort(so, 0, ac - 2);
	i = -1;
	while (++i < ac - 1)
		ft_lstadd_back(&s->sorted, ft_lstnew(so[i], i));
}

static void	put_indexes(sts *s)
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
				break;
			}
			else
				s->sorted = s->sorted->next;
		}
		s->a = s->a->next;
	}
	s->a = tmp1;
	s->sorted = tmp2;
}

int	main(int ac, char *av[])
{
	sts	s;

	if (ac < 2)
		return (0);
	s.a = NULL;
	s.b = NULL;
	s.sorted = NULL;
	s.count_actions = 0;
	fill_stack_a(&s, ++av);
	fill_stack_sorted(&s, ac);
	put_indexes(&s);
	do_stuff(&s);

//	printf("%d", s.count_true);




//
//	ra(&s,0);
//	ra(&s,0);
//	ra(&s,0);
//	pb(&s,0);
//	pb(&s,0);
//	pb(&s,0);
//	ra(&s,0);
//	pa(&s,0);
//	ra(&s,0);
//	pa(&s,0);
//
//	ra(&s,0);
//	pa(&s,0);
//	ra(&s,0);


//	printf("actions : %d\n", s.count_actions);
//	printf("shifts  : %d\n", s.count_true1);
//	printf("shifts  : %d\n", s.count_true2);

	printf("\nStuck a\n");
			while (s.a)
			{
				printf("%d-%d >> A:%d, S:%d\n", s.a->i, s.a->num, s.a->stay_a, s.a->gt_status);
//				printf("%d-%d >> %d\n", s.a->i, s.a->num, s.a->status2);
//				printf("%d ", s.a->num);
				s.a = s.a->next;
			}

				printf("\n\nStuck b\n");
			while (s.b)
			{
				printf("%d ", s.b->num);
				s.b = s.b->next;
			}

				printf("\n\nSorted\n");
			while (s.sorted)
			{
				printf("%d ", s.sorted->num);
				s.sorted = s.sorted->next;
			}

	return (0);
}
