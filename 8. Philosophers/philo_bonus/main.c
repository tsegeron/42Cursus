/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:55:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/14 17:10:38 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/philo.h"

static void	free_memory(t_s **s, t_list **philo)
{
	free((*s)->family);
	(*philo)->prev->next = NULL;
	ft_lstclear(philo);
	(*s)->philos_count = 0;
	(*s)->t2die = 0;
	(*s)->t2eat = 0;
	(*s)->t2sleep = 0;
	(*s)->num_eat = 0;
	(*s)->die_status = 0;
	free(*s);
	sem_close((*s)->sem_fork);
	sem_close((*s)->sem_stdout);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_STDOUT);
}

int	main(int ac, char **av)
{
	t_s		*s;
	t_list	*philo;

	s = ft_calloc(1, sizeof(t_s));
	if (!s)
		return (error_write("Error: malloc\n"));
	philo = NULL;
	if (parse_input(ac, &av, &s, &philo))
		return (-1);
	if (gettimeofday(&s->start_time, NULL))
		return (error_write("Error: gettimeofday\n"));
	if (semaphores_init(&s))
		return (-1);
	if (launch_thread_and_processes(s, philo))
		return (-1);
	free_memory(&s, &philo);
	return (0);
}
