/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:05:32 by gernesto          #+#    #+#             */
/*   Updated: 2021/10/10 22:09:00 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>	/* :::::size_t::::: */
# include <stdlib.h>	/* :::::malloc::::: */
# include <unistd.h>	/* ::::::write::::: */
# include <stdio.h>		/* ::::::test:::::: */
# include <strings.h>	/* ::::::test:::::: */
# include <string.h>	/* ::::::test:::::: */
# include <ctype.h>		/* ::::::test:::::: */
# include <fcntl.h>		/* ::::::test:::::: */

typedef struct	s_list
{
	void 			*content;
	struct s_list	*next;
}	t_list;

/* ::::::::::::::::::::::::::::::::> Part 1 <:::::::::::::::::::::::::::::::: */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, void *restrict src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlcpy(char *restrict dst,
			 const char *restrict src, size_t dstsize);
size_t	ft_strlcat(char *restrict dst,
			 const char *restrict src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
/* ::::::::::::::::::::::::::::::::> Part 1 <:::::::::::::::::::::::::::::::: */

/* ::::::::::::::::::::::::::::::::> Part 2 <:::::::::::::::::::::::::::::::: */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/* ::::::::::::::::::::::::::::::::> Part 2 <:::::::::::::::::::::::::::::::: */

/* ::::::::::::::::::::::::::::::> Bonus part <:::::::::::::::::::::::::::::: */
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void	*));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/* ::::::::::::::::::::::::::::::> Bonus part <:::::::::::::::::::::::::::::: */

#endif	/* ::::::LIBFT_H:::::: */

/* #include "libft.h" */