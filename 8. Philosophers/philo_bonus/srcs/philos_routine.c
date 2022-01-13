/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:37:27 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/14 01:52:45 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/philo.h"

static void	*check_for_death(void *tmp)
{
	t_list			*philo;
	unsigned long	cur_time;

	philo = (t_list *)tmp;
	while (1)
	{
		cur_time = get_time_passed(philo->s);
		if (cur_time > philo->last_meal + philo->s->t2die
			&& philo->eat_num < (unsigned long )philo->s->num_eat)
		{
			philo->s->die_status = 1;
			write_action(philo->s, philo->philo_num, 'd');
			sem_wait(philo->s->sem_stdout);
			exit(2);
		}
	}
}

int	philo_routine(t_list *philo)
{
	if (philo->philo_num % 2)
		usleep(500);
	if (pthread_create(&philo->death_check, NULL, &check_for_death, philo))
		exit(error_write("Error: thread: create\n"));
	if (pthread_detach(philo->death_check))
		exit(error_write("Error: thread: detach\n"));
	while (!philo->s->die_status)
	{
		sem_wait(philo->s->sem_fork);
		write_action(philo->s, philo->philo_num, 'f');
		sem_wait(philo->s->sem_fork);
		write_action(philo->s, philo->philo_num, 'f');
		write_action(philo->s, philo->philo_num, 'e');
		philo->last_meal = get_time_passed(philo->s);
		smart_sleep(philo->s, philo->s->t2eat);
		sem_post(philo->s->sem_fork);
		sem_post(philo->s->sem_fork);
		philo->eat_num += 1;
		if ((long long)philo->eat_num == philo->s->num_eat)
			exit(1);
		write_action(philo->s, philo->philo_num, 's');
		smart_sleep(philo->s, philo->s->t2sleep);
		write_action(philo->s, philo->philo_num, 't');
	}
	exit(2);
}
