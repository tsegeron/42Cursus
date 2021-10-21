#ifndef FT_DO_OP_H
# define FT_DO_OP_H

int				ft_strlen(char *str);
void			ft_putnbr(long long int nb);
long long int	ft_atoi(char *str);
long long int	check_operator(char *operator);
int				check_divmod_0(int operator, long long int b);
void			print_result(int operator, long long int a, long long int b);

#endif
