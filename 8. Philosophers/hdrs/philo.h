/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:10:08 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/08 21:35:35 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX 4294967

typedef struct s2
{
	unsigned long	philo_num;
	unsigned long	eat_num;
//	int				fork_status;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s
{
	pthread_t		*thread;
	t_philo			*philo;
	unsigned long	philos_count;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	long long		num_eat;
	int				die_status;
	int				i;
	struct timeval	time;
	long			ms;
//	pthread_mutex_t	*fork;
}	t_s;

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
long long	ft_atoi(const char *str, int *check_zero);

int			parse_input(int ac, char ***av, t_s *s);

#endif
