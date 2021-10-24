/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 04:54:28 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/24 04:54:32 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//# define BUFFER_SIZE 1
//# define BUFFER_SIZE 41
//# define BUFFER_SIZE 42
//# define BUFFER_SIZE 1000000

/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */
# include <stdlib.h>	/* :::::malloc::::: */
# include <unistd.h>	/* ::::::read:::::: */
# include <fcntl.h>		/* ::::::open:::::: */
# include <stdio.h>		/* ::::::test:::::: */
/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */

/* ::::::::::::::::::::::::::::::> Prototypes <:::::::::::::::::::::::::::::: */
char	*get_next_line(int fd);

int		ft_strlen(const char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(char *s, char c);
/* ::::::::::::::::::::::::::::::> Prototypes <:::::::::::::::::::::::::::::: */

#endif /* :::GET_NEXT_LINE_BONUS_H::: */
