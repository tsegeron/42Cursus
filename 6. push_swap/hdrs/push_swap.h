/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:55:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/25 23:41:05 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error!\n"

# include <stdlib.h>	/* malloc, free, exit	*/
# include <unistd.h>	/* write, read			*/

# include <stdio.h>		/* test					*/

typedef struct s_list
{
	int				num;
	int				i;
	int				stay_a;
	int				gt_status;
	int				actions_num_a;
	int				actions_num_b;
	int				actions_to_pa;
	struct s_list	*next;
}	t_list;

typedef struct stucks
{
	t_list	*a;
	t_list	*b;
	t_list	*sorted;
	int		count_actions;
}	t_s;

typedef struct merge
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		*left;
	int		*right;
}	t_for_merge;

void	check_args(char *av[], char ***split);
void	merge_sort(int **a, size_t start, size_t end);

size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(char *s, char c);
int		ft_atoi(const char *str, int *check_zero);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int num, int i);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstprelast(t_list *lst);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd, int buf_size);

int		fill_stacks(t_s *s, char ***split);
int		check_for_duplicates(t_s *s);

void	sa(t_s *s, int q, int w);
void	sb(t_s *s, int q);
void	ss(t_s *s, int q);
void	pa(t_s *s, int q);
void	pb(t_s *s, int q);
void	ra(t_s *s, int q);
void	rb(t_s *s, int q);
void	rr(t_s *s, int q);
void	rra(t_s *s, int q);
void	rrb(t_s *s, int q);
void	rrr(t_s *s, int q);

t_list	*gt_find_start(t_s *s);
void	gt_set_statuses(t_s *s);

void	count_needed_actions_for_a(t_s *s);
void	count_needed_actions_for_b(t_s *s);
void	count_actions_to_pa(t_s *s);

void	move_to_b1(t_s *s, int num);
void	move_to_b2(t_s *s, int num);
void	move_to_a(t_s *s, int num);
void	align_stack_a(t_s *s, int num);

void	print_stacks(t_s *s);

#endif //PUSH_SWAP_H
