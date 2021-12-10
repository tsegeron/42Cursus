/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:55:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/12/10 12:28:24 by gernesto         ###   ########.fr       */
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
//	int				status;
//	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

//typedef struct stucks
//{
//	int		len_a;
//	int		len_b;
//	t_list	*a;
//	t_list	*b;
//	t_list	*sorted;
//	int
//
//}	sts;



int		check_args(int **a,int **b, int ac, char *av[]);
int		ft_atoi(const char *str, int *check_zero);
void	merge_sort(int a[], size_t start, size_t end);

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int num, int i);

void	sa(t_list **a, int q);
void	sb(t_list **b, int q);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, int q);
void	pb(t_list **b, int q);




#endif //PUSH_SWAP_H
