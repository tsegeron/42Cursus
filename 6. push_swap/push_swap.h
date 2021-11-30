/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:55:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/11/11 09:23:30 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error!\n"

# include <stdlib.h>	/* malloc, free, exit	*/
# include <unistd.h>	/* write, read			*/

# include <stdio.h>		/* test					*/

int	check_args(int **a,int **b, int ac, char *av[]);
int	ft_atoi(const char *str, int *check_zero);

#endif //PUSH_SWAP_H
