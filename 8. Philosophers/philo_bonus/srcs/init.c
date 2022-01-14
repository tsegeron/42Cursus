/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:34:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/14 17:25:50 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static void	waitpid_cycle(t_s *s, int **ret)
{
	int				child_stat;
	unsigned int	i;

	i = -1;
	**ret = 0;
	while (++i < s->philos_count)
	{
		if (waitpid(-1, &child_stat, 0) < 0)
		{
			error_write("Error: waitpid\n");
			break ;
		}
		if (WSTOPSIG(child_stat) == 1)
		{
			**ret += 1;
			if (**ret == (int )s->philos_count)
				break ;
		}
		else if (WSTOPSIG(child_stat) == 2)
		{
			**ret = 0;
			break ;
		}
	}
}

static void	*end_check_loop(void *copy_s)
{
	t_s				*s;
	int				*ret;

	s = (t_s *)copy_s;
	ret = malloc(sizeof(int));
	if (!ret)
		return (NULL);
	waitpid_cycle(s, &ret);
	return ((void *)ret);
}

static int	launch_child_processes(t_s *s, t_list *philo)
{
	unsigned int	i;

	i = -1;
	s->family = (pid_t *)ft_calloc(s->philos_count, sizeof(pid_t));
	if (!s->family)
		return (error_write("Error: malloc\n"));
	while (++i < s->philos_count)
	{
		s->family[i] = fork();
		if (s->family[i] < 0)
			exit(error_write("Error: fork\n"));
		if (!s->family[i])
		{
			philo_routine(philo);
			exit(5);
		}
		philo = philo->next;
	}
	philo = philo->next;
	return (0);
}

int	launch_thread_and_processes(t_s *s, t_list *philo)
{
	unsigned int	i;
	int				*res;

	if (pthread_create(&s->thread, NULL, &end_check_loop, s))
		return (error_write("Error: thread: create\n"));
	if (launch_child_processes(s, philo))
		return (-1);
	if (pthread_join(s->thread, (void **)&res))
		return (error_write("Error: thread: join\n"));
	if (*res == (int )s->philos_count)
		free(res);
	else if (!(*res))
	{
		free(res);
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
