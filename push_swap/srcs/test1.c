#include "../hdrs/push_swap.h"

static void	fill_stack_a(sts *s, char *av[])
{
	int	i;
	int	check_zero;

	i = 0;
	while (*av)
	{
		check_zero = 0;
		ft_lstadd_back(&s->a, ft_lstnew(ft_atoi(*av++, &check_zero), i++));
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

int	main(int ac, char *av[])
{
	sts	s;

	if (ac < 2)
		return (0);
	s.a = NULL;
	s.b = NULL;
	s.sorted = NULL;
	fill_stack_a(&s, ++av);
	fill_stack_sorted(&s, ac);
	sa(&s, 0);
	pb(&s, 0);
//	pb(&s, 0);
//	printf("%d", a->num);







//	printf("Before\n");
while (s.a)
{
	printf("%d ", s.a->num);
	s.a = s.a->next;
}
	printf("\n");
while (s.b)
{
	printf("%d ", s.b->num);
	s.b = s.b->next;
}
//	printf("\nAfter\n");
//while (s.sorted)
//{
//	printf("%d ", s.sorted->num);
//	s.sorted = s.sorted->next;
//}

	return (0);
}
