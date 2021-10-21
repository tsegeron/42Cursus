SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJS = ${SRCS:.c=.o}

HEAD = ft.h

GCC = gcc

GFL = -Wall -Wextra -Werror

COM = ${GCC} ${GFL}

NAME = libft.a

RM = rm -f

1 = cd srcs

2 = ${COM} -c ${SRCS}

3 = ar rc ${NAME} ${OBJS} ../includes/${HEAD} 

4 = mv ${NAME} ..

re:		fclean all
		
all:	${NAME}
		
libft.a:
		${1} && ${2} && ${3} && ${4}

clean:
		cd srcs && ${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

.PHONY: re all libft.a clean fclean
