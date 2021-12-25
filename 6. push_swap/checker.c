/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:39:36 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/25 23:43:28 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/push_swap.h"

static void	clear_all(t_s *s, char ***split)
{
	int	i;

	i = 0;
	ft_lstclear(&s->a);
	ft_lstclear(&s->b);
	ft_lstclear(&s->sorted);
	while ((*split)[i])
		free((*split)[i++]);
	free(*split);
}

static int	num_of_elements_to_be_moved(t_s *s)
{
	t_list	*head;
	int		count;

	count = 0;
	head = s->a;
	while (head)
	{
		if (head->gt_status)
			count++;
		head = head->next;
	}
	return (count);
}

static void	do_actions(t_s *s, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(s, 1, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(s, 1);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(s, 1);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(s, 1);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(s, 1);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(s, 1);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(s, 1);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(s, 1);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(s, 1);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(s, 1);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(s, 1);
	else
		exit(write(2, "Error\n", 6));
}

static void	read_actions(t_s *s)
{
	char	*line;

	line = get_next_line(0, 1);
	if (!line)
		return ;
	while (line[0] != '\n')
	{
		do_actions(s, line);
		free(line);
		line = get_next_line(0, 1);
		if (!line)
			return ;
	}
	free(line);
	line = NULL;
}

int	main(int ac, char *av[])
{
	char	**split;
	t_s		s;

	if (ac < 2)
		return (0);
	check_args(++av, &split);
	if (!fill_stacks(&s, &split))
		return ((int )write(2, "Error\n", 6));
	read_actions(&s);
	gt_set_statuses(&s);
	if (!s.b && s.a->i == 0 && num_of_elements_to_be_moved(&s) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_all(&s, &split);
	return (0);
}
