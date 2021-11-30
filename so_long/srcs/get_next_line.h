/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:43:18 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/23 20:50:55 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define BUFFER_SIZE 1
//# define BUFFER_SIZE 41
//# define BUFFER_SIZE 42
//# define BUFFER_SIZE 1000000

/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */
# include <stdlib.h>	/* :::::malloc::::: */
# include <unistd.h>	/* ::::::read:::::: */
/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */

/* ::::::::::::::::::::::::::::::> Prototypes <:::::::::::::::::::::::::::::: */
//char	*get_next_line(int fd);

int		ft_strlen(const char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(char *s, char c);
/* ::::::::::::::::::::::::::::::> Prototypes <:::::::::::::::::::::::::::::: */

#endif /* :::GET_NEXT_LINE_H::: */