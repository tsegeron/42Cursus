/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:55:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/11 21:25:53 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs_b/philo.h"

int	main(int ac, char **av)
{
	t_s		*s;
	t_list	*philo;

	s = ft_calloc(1, sizeof(t_s));
	if (!s)
		return (printf("Error: malloc\n"));
	if (parse_input(ac, &av, &s))
		return (-1);
	philo = NULL;
	if (philos_and_mutexes_init(&s, &philo))
		return (-1);
	if (gettimeofday(&s->start_time, NULL))
		return (printf("Error: gettimeofday\n"));
	if (threads_init(s, philo))
		return (-1);
	loop_at_exit(s, philo);
	if (destroy_mutexes_at_exit(s, philo))
		return (-1);
	return (0);
}
