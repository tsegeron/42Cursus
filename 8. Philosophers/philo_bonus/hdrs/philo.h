/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:16 by gernesto          #+#    #+#             */
/*   Updated: 2022/01/14 17:35:45 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * philo: bonus part
 */
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define MAX 4294967
# define SEM_FORK "philo_42_sem_fork"
# define SEM_STDOUT "philo_42_sem_stdout"
# define MSG_FORK " has taken a fork\n"
# define MSG_EAT " is eating\n"
# define MSG_SLEEP " is sleeping\n"
# define MSG_THINK " is thinking\n"
# define MSG_DIE " died\n"

typedef struct s
{
	pthread_t		thread;
	unsigned long	philos_count;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	long long		num_eat;
	sem_t			*sem_fork;
	sem_t			*sem_stdout;
	pid_t			*family;
	int				die_status;
	struct timeval	start_time;
}	t_s;

typedef struct s2
{
	unsigned long	philo_num;
	unsigned long	eat_num;
	unsigned long	last_meal;
	pthread_t		death_check;
	t_s				*s;
	struct s2		*next;
	struct s2		*prev;
}	t_list;

unsigned long	ft_lstsize(t_list *lst);
t_list			*ft_lstnew(int num, t_s *s);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstclear(t_list **lst);
void			ft_lstadd_back(t_list **lst, t_list *new);

long long		ft_atoi(const char *str, int *check_zero);
size_t			ft_strlen(const char *str);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strjoin(char *s1, char *s2);

int				error_write(char *msg);

int				parse_input(int ac, char ***av, t_s **s, t_list **philo);
int				semaphores_init(t_s **s);
int				launch_thread_and_processes(t_s *s, t_list *philo);
int				get_time_passed(t_s *s);
int				philo_routine(t_list *philo);
int				write_action(t_s *s, unsigned long philo, char c);
void			smart_sleep(t_s *s, unsigned long t2do);

#endif
