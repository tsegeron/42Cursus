/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:55:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/14 19:07:11 by gernesto         ###   ########.fr       */
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
	int				status1;
	int				count2;
	int				status2;
	int				sublen;
//	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct stucks
{
	int		len_a;
	int		len_b;
	t_list	*a;
	t_list	*b;
	t_list	*sorted;
	int		count_true1;
	int		count_true2;
	int		count_actions;
//	int

}	sts;



int		check_args(int **a,int **b, int ac, char *av[]);
int		ft_atoi(const char *str, int *check_zero);
void	merge_sort(int a[], size_t start, size_t end);

int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int num, int i);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstprelast(t_list *lst);

void	sa(sts *s, int q);
void	sb(sts *s, int q);
void	ss(sts *s, int q);
void	pa(sts *s, int q);
void	pb(sts *s, int q);
void	ra(sts *s, int q);
void	rb(sts *s, int q);
void	rr(sts *s, int q);
void	rra(sts *s, int q);
void	rrb(sts *s, int q);
void	rrr(sts *s, int q);

void	do_magic(sts *s);
//void	set_statuses(sts *s);
//void	set_statuses_in_ascending_index_order(sts *s);
//void	set_statuses_plus_one_index_order(sts *s);
t_list *gt_find_start(sts *s);
void	do_stuff(sts *s);




#endif //PUSH_SWAP_H
