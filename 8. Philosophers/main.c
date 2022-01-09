/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:55:45 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/09 13:52:22 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/philo.h"

int	get_time_passed(t_philo *tmp, unsigned long *res)
{
	if (!tmp->philo_timer.tv_sec)
	{
		*res = 0;
		if (gettimeofday(&tmp->philo_timer, NULL))
		{
			printf("Error: gettime\n");
			return (-1);
		}
	}
	else
	{
		*res = tmp->philo_timer.tv_sec;
		if (gettimeofday(&tmp->philo_timer, NULL))
		{
			printf("Error: gettime\n");
			return (-1);
		}
		*res = tmp->philo_timer.tv_sec - *res;
	}
	return (0);
}

int	print_action()
{

	return (0);
}

void	*philo_routine(void *s)
{
	unsigned long	start_time;
	unsigned long	i;
	unsigned long	j;
	unsigned long	*res;
	t_s				*tmp;

	tmp = (t_s *)s;
	i = tmp->i;
	if (i == 0)
		j = tmp->philos_count - 1;
	else
		j = i - 1;
	res = ft_calloc(1, sizeof(long long));
	if (get_time_passed(&tmp->philo[i], res))
	{
		*res =  printf("Error: gettime\n") * i * 100;
		return ((void *)res);
	}
	start_time = *res;
	pthread_mutex_lock(&tmp->philo[i].fork);
	printf("Time: %lu >> Philo %lu has taken #1 fork\n", tmp->philo[i].philo_timer.tv_sec - start_time, tmp->philo[i].philo_num);
	pthread_mutex_lock(&tmp->philo[j].fork);
	printf("Time: %lu >> Philo %lu has taken #2 fork\n", tmp->philo[i].philo_timer.tv_sec - start_time, tmp->philo[i].philo_num);
	printf("Time: %lu >> Philo %lu is eating\n", tmp->philo[i].philo_timer.tv_sec - start_time, tmp->philo[i].philo_num);
	usleep(tmp->t2eat * 1000);
	if (gettimeofday(&tmp->philo[i].philo_timer, NULL))
	{
		*res = printf("Error: gettime\n") * i * 100;
		return ((void *)res);
	}
	printf("Time: %lu >> Philo %lu is sleeping\n", tmp->philo[i].philo_timer.tv_sec - start_time, tmp->philo[i].philo_num);
	usleep(tmp->t2sleep * 1000);



	tmp->philo[i].eat_num += 1;
	pthread_mutex_unlock(&tmp->philo[i].fork);
	pthread_mutex_unlock(&tmp->philo[j].fork);
	return (res);
}

int	init_threads(t_s *s)
{
	unsigned long	*res;

	s->thread = ft_calloc(s->philos_count, sizeof(pthread_t));
//	if (pthread_mutex_init(&s->mutex, NULL))
//		return (printf("Error: mutex: init\n"));
	s->i = -1;
	while (++s->i < s->philos_count)
		if (pthread_create(&s->thread[s->i], NULL, philo_routine, s))
			return (printf("Error: thread: init\n"));
	s->i = -1;
	while (++s->i < s->philos_count)
	{
		if (pthread_join(s->thread[s->i], (void **)&res))
			return (printf("Error: thread: join\n"));
		if (*res)
		{
			printf("Error occurred in thread %lu\n", *res / 100);
			free (res);
			return (-1);
		}
		free (res);
	}


	return (0);
}

int main(int ac, char **av)
{
	t_s	s;

	if (parse_input(ac, &av, &s))
		return (-1);
//	printf("%lu %lu %lu %lu %lld\n", s.philos_count, s.t2die, s.t2eat, s.t2sleep, s.num_eat);

//	if (gettimeofday(&s.time, NULL))
//		return (printf("Error: gettime\n"));
//	s.ms = s.time.tv_sec;

//	for(int i = 0; i < s.philos_count; i++)
//		printf("%d %d %d\n", s.philo[i].philo_num, s.philo[i].eat_num, s.philo[i].fork_status);
	if (!s.die_status)
	{
		if (init_threads(&s))
			return (-1);
	}
	else
		return (0);
//
//
//
//
//
//
//	if (destroy_theads(&s))
//		return (-1);


	return (0);
}




/*


 if (pthread_mutex_destroy(&s->mutex))
		return (printf("Error: mutex: destroy\n"));
 */
