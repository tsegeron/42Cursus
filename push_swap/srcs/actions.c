#include "../hdrs/push_swap.h"

void	sa(t_list **a, int q)
{
	int	tmp;

	tmp = (*a)->num;
	if (ft_lstsize(*a) > 1)
	{
		(*a)->num = (*a)->next->num;
		(*a)->next->num = tmp;
		if (!q)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list **b, int q)
{
	int	tmp;

	tmp = (*b)->num;
	if (ft_lstsize(*b) > 1)
	{
		(*b)->num = (*b)->next->num;
		(*b)->next->num = tmp;
		if (!q)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}

void	pa(t_list **a, int q)
{
	if (ft_lstsize(*b) > 0)
	{

		if (!q)
			write(1, "pa\n", 3);
	}

}

void	pb(t_list **b, int q)
{
	if (ft_lstsize(*a) > 0)
	{

		if (!q)
			write(1, "pb\n", 3);
	}

}
