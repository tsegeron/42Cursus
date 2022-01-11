/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:10:08 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/11 21:00:38 by gernesto         ###   ########.fr       */
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
# define MSG_FORK " has taken a fork\n"
# define MSG_EAT " is eating\n"
# define MSG_SLEEP " is sleeping\n"
# define MSG_THINK " is thinking\n"
# define MSG_DIE " died\n"

typedef struct s
{
	pthread_t		*thread;
	unsigned long	philos_count;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	long long		num_eat;
	int				die_status;
	int				i;
	struct timeval	start_time;
	pthread_mutex_t	stdout_stat;
}	t_s;

typedef struct s2
{
	unsigned long	philo_num;
	unsigned long	eat_num;
	unsigned long	last_meal;
	pthread_mutex_t	fork;
	t_s				*s;
	struct s2		*next;
	struct s2		*prev;
}	t_list;

t_list		*ft_lstnew(int num, t_s *s);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);

size_t		ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);
long long	ft_atoi(const char *str, int *check_zero);

int			parse_input(int ac, char ***av, t_s **s);
int			philos_and_mutexes_init(t_s **s, t_list **philo);
int			threads_init(t_s *s, t_list *philo);
void		*philo_routine(void *s);
int			get_time_passed(t_s *s);
int			write_action(t_s *s, unsigned long philo, char c);
void		smart_sleep(t_s *s, unsigned long t2do);
void		loop_at_exit(t_s *s, t_list *philo);
int			destroy_mutexes_at_exit(t_s *s, t_list *philo);

#endif
