/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:09:57 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/20 21:36:43 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H

/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */
# include <stdarg.h>	/* :::::va_list:::: */
# include <stdlib.h>	/* :::::malloc::::: */
# include <unistd.h>	/* :::::write:::::: */
/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */

/* :::::::::::::::::::::::::::::::> Structure <:::::::::::::::::::::::::::::: */
typedef struct s_l
{
	va_list	ap;
	char	*tmp;
	int		count;
	int		ct;
	int		i;
	int		minus;
	int		plus;
	int		space;
	int		mark;
	int		zero;
	int		width;
	int		accur;
	int		accur_xX;
}	t_l;
/* :::::::::::::::::::::::::::::::> Structure <:::::::::::::::::::::::::::::: */

/* :::::::::::::::::::::::::::::::> Prototypes <::::::::::::::::::::::::::::: */
int		check_conv(const char *s, t_l *st);
int		ft_printf(const char *string, ...);
void	do_cases(t_l *st);
void	do_flags(const char *s, t_l *st);

void	zero_struct(t_l *st);
void	do_case_c(t_l *st);
void	do_case_s(char *s, t_l *st);
void	do_case_p(char *s, t_l *st);
void	do_case_di(char *s, t_l *st);
void	do_case_u(char *s, t_l *st);
void	do_case_x(char *s, t_l *st);
void	do_case_x_up(char *s, t_l *st);
void	do_case_perc(t_l *st);

char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_strlen(const char *str);
char	*ft_itoa_uns(unsigned int n);
char	*ft_itoa_hex(unsigned int n);
char	*ft_itoa_lhex(unsigned long long n);
void	ft_putstr_fd_c(char *s, t_l *st, int fd);
void	ft_putchar_fd_c(char c, t_l *st, int fd);
/* :::::::::::::::::::::::::::::::> Prototypes <::::::::::::::::::::::::::::: */

#endif /* :::::PRINTFT_H::::: */
