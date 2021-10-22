/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:43:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/22 22:27:56 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */
# include <stdlib.h>	/* :::::malloc::::: */
# include <unistd.h>	/* ::::::read:::::: */
# include <fcntl.h>		/* ::::::open:::::: */
# include <stdio.h>		/* ::::::test:::::: */
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
	int		accur_x;
}	t_l;

typedef struct s_list
{
	int				fd;
	int				line;
	char			*full;
	char			*ret;
	char			*left;
	struct s_list	*prev;
	struct s_list	*next;
}	t_st;
/* :::::::::::::::::::::::::::::::> Structure <:::::::::::::::::::::::::::::: */

/* ::::::::::::::::::::::::::::::> Prototypes <:::::::::::::::::::::::::::::: */
char	*get_next_line(int fd);

int		ft_strlen(const char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(char *s);
/* ::::::::::::::::::::::::::::::> Prototypes <:::::::::::::::::::::::::::::: */

#endif /* :::GET_NEXT_LINE_H::: */