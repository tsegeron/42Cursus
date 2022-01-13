/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:49:57 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/13 18:48:31 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	create_philos_list(t_s **s, t_list **philo)
{
	t_list			*lst_start;
	t_list			*lst_last;
	unsigned long	i;

	(*s)->die_status = 0;
	i = -1;
	while (++i < (*s)->philos_count)
		ft_lstadd_back(&(*philo), ft_lstnew(i + 1, (*s)));
	if (ft_lstsize(*philo) != (*s)->philos_count)
		return (error_write("Error: malloc\n"));
	lst_start = (*philo);
	lst_last = ft_lstlast((*philo));
	lst_last->next = (*philo);
	(*philo)->prev = lst_last;
	(*philo) = lst_start;
	return (0);
}

int	parse_input(int ac, char ***av, t_s **s, t_list **philo)
{
	int	i;
	int	status[5];

	if (ac < 5)
		return (error_write("Error: lack of arguments\n"));
	else if (ac > 6)
		return (error_write("Error: arguments: more than needed\n"));
	i = 0;
	(*s)->num_eat = -1;
	(*s)->philos_count = ft_atoi((*av)[++i], &status[0]);
	(*s)->t2die = ft_atoi((*av)[++i], &status[1]);
	(*s)->t2eat = ft_atoi((*av)[++i], &status[2]);
	(*s)->t2sleep = ft_atoi((*av)[++i], &status[3]);
	status[4] = -1;
	if (ac == 6)
		(*s)->num_eat = ft_atoi((*av)[++i], &status[4]);
	if (!status[0] || !status[1] || !status[2] || !status[3] || !status[4] || \
	(*s)->t2die > MAX || (*s)->t2eat > MAX || (*s)->t2sleep > MAX || \
	(*s)->philos_count < 1 || !(*s)->num_eat)
		return (error_write("Error: invalid arguments\n"));
	return (create_philos_list(s, philo));
}
