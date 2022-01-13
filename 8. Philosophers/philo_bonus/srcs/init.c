/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:34:13 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/14 01:13:21 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static void	*end_check_loop(void *copy_s)
{
	t_s	*s;
	int	*ret;
	int	child_stat;
	int	i;

	s = (t_s *)copy_s;
	ret = malloc(sizeof(int));
	if (!ret)
		return (NULL);
	i = -1;
	*ret = 0;
	while (++i < s->philos_count)
	{
		if (waitpid(-1, &child_stat, 0) < 0)
		{
			perror("Error >>");
			error_write("Error: waitpid\n");
			break ;
		}
		if (WSTOPSIG(child_stat) == 1)
		{
//			printf("THERE");
			*ret += 1;
			if (*ret == s->philos_count)
				break ;
		}
		else if (WSTOPSIG(child_stat) == 2)
		{
//			printf("HERE");
			*ret = 0;
			break ;
		}
	}
	return ((void *)ret);
}

int	launch_thread_and_processes(t_s *s, t_list *philo)
{
	unsigned int	i;
	int				*res;

	if (pthread_create(&s->thread, NULL, &end_check_loop, s))
		return (error_write("Error: thread: create\n"));
	i = -1;
	s->family = (pid_t *)ft_calloc(s->philos_count, sizeof(pid_t));
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
	if (pthread_join(s->thread, (void **)&res))
		return (error_write("Error: thread: join\n"));
	printf(">>>>%d\n", *res);
	if (!*res || *res == s->philos_count)
	{
		free(res);
		exit(printf("Imitation finished\n"));
	}
	free(res);
	return (0);
}

int	semaphores_init(t_s **s)
{
	sem_unlink(SEM_FORK); // Check?
	sem_unlink(SEM_STDOUT); // Check?
	(*s)->sem_fork = sem_open(SEM_FORK, O_CREAT, 0660, (*s)->philos_count);
	if ((*s)->sem_fork == SEM_FAILED)
		return (error_write("Error: semaphore: open\n"));
	(*s)->sem_stdout = sem_open(SEM_STDOUT, O_CREAT, 0660, 1);
	if ((*s)->sem_stdout == SEM_FAILED)
		return (error_write("Error: semaphore: open\n"));
	return (0);
}
