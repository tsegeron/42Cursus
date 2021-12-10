#include "../hdrs/push_swap.h"

static void	fill_stack_a(t_list **a, char *av[])
{
	int	i;
	int	check_zero;

	i = 0;
	while (*av)
	{
		check_zero = 0;
		ft_lstadd_back(a, ft_lstnew(ft_atoi(*av++, &check_zero), i++));
		if (!(*a)->num && !check_zero)
		{
			free (*a);
			return ;
		}
	}
}

static void	fill_stack_sorted(t_list **sorted, t_list **a, int ac)
{
	t_list	*tmp;
	int	s[ac - 1];
	int	i;

	i = 0;
	tmp = *a;

	while ((*a))
	{
		s[i++] = (*a)->num;
		(*a) = (*a)->next;
	}
	*a = tmp;
	merge_sort(s, 0, ac - 2);
	i = -1;
	while (++i < ac - 1)
		ft_lstadd_back(sorted, ft_lstnew(s[i], i));
}

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	t_list	*sorted;

	if (ac < 2)
		return (0);
	a = NULL;
	sorted = NULL;
	fill_stack_a(&a, ++av);
	fill_stack_sorted(&sorted, &a, ac);
	sa(&a, 0);







//	printf("Before\n");
while (a)
{
	printf("%d -> %d\n", a->i, a->num);
	a = a->next;
}
//	printf("\nAfter\n");
//while (sorted)
//{
//	printf("%d -> %d\n", sorted->i, sorted->num);
//	sorted = sorted->next;
//}

	return (0);
}
