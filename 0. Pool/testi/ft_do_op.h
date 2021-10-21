/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:16:46 by gernesto          #+#    #+#             */
/*   Updated: 2021/08/04 17:17:07 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

int    ft_strlen(char *str);
void    ft_putnbr(int nb);
int		ft_atoi(char *str);
int		check_operator(char *operator);
int		check_divmod_0(int operator, int b);
void	print_result(int operator, int a, int b);

#endif
