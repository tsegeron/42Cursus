/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:34:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/14 18:49:18 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static int	end_check_loop(t_s *s, int *res)
{
	int				child_stat;
	unsigned int	i;

	i = -1;
	while (++i < s->philos_count)
	{
		if (waitpid(-1, &child_stat, 0) == -1)
			return (error_write("Error: waitpid\n"));
		if (WSTOPSIG(child_stat) == 1)
		{
			*res += 1;
			if (*res == (int )s->philos_count)
				break ;
		}
		else if (WSTOPSIG(child_stat) == 2)
		{
			*res = 0;
			break ;
		}
	}
	return (0);
}

static int	launch_child_processes(t_s *s, t_list *philo)
{
	unsigned int	i;

	i = 0;
	s->family = (pid_t *)ft_calloc(s->philos_count, sizeof(pid_t));
	if (!s->family)
		return (error_write("Error: malloc\n"));
	while (i < s->philos_count)
	{
		s->family[i] = fork();
		if (s->family[i] < 0)
			exit(error_write("Error: fork\n"));
		if (!s->family[i])
			philo_routine(philo);
		i++;
		philo = philo->next;
	}
	philo = philo->next;
	return (0);
}

int	launch_thread_and_processes(t_s *s, t_list *philo)
{
	unsigned int	i;
	int				res;

	if (launch_child_processes(s, philo))
		return (-1);
	res = 0;
	if (end_check_loop(s, &res))
		return (-1);
	if (res == (int )s->philos_count)
		return (0);
	else if (!(res))
	{
		i = -1;
		while (++i < s->philos_count)
			kill(s->family[i], SIGUSR1);
	}
	return (0);
}

int	semaphores_init(t_s **s)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_STDOUT);
	(*s)->sem_fork = sem_open(SEM_FORK, O_CREAT, 0660, (*s)->philos_count);
	if ((*s)->sem_fork == SEM_FAILED)
		return (error_write("Error: semaphore: open\n"));
	(*s)->sem_stdout = sem_open(SEM_STDOUT, O_CREAT, 0660, 1);
	if ((*s)->sem_stdout == SEM_FAILED)
		return (error_write("Error: semaphore: open\n"));
	return (0);
}
