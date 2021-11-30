#ifndef SO_LONG_H
#define SO_LONG_H

/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */
# include <stdio.h>		/* printf, perror, strerror	*/
# include <unistd.h>	/* close, write, read		*/
# include <stdlib.h>	/* malloc, free, exit		*/
# include <fcntl.h>		/* open						*/
# include <mlx.h>

/* ::::::::::::::::::::::::::::::::> headers <::::::::::::::::::::::::::::::: */
int		ft_strlen(const char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(char *s, char c);
char	*get_next_line(int fd, int buf_size);



/* :::::::::::::::::::::::::::::::> Structure <:::::::::::::::::::::::::::::: */

/* :::::::::::::::::::::::::::::::> Structure <:::::::::::::::::::::::::::::: */




#endif //SO_LONG_H
