# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: gernesto <gernesto@student.21-school.ru>   +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/10/08 14:05:39 by gernesto          #+#    #+#             #
#   Updated: 202#   Updated: 2021/10/12 00:14:29 by gernesto         ###   ########.fr       #                                                              #
# ************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2

RM = rm -rf
AR = ar rcs

# ------------------------------------------------------------------------------

NAME = libft.a
ENAME = exec

HDRS = libft.h

SRCS =		ft_isalpha.c		ft_isdigit.c		ft_isalnum.c	\
			ft_isascii.c		ft_isprint.c		ft_strlen.c		\
			ft_bzero.c			ft_memset.c			ft_memcpy.c		\
			ft_memmove.c		ft_memchr.c			ft_memcmp.c		\
			ft_toupper.c		ft_tolower.c		ft_strlcpy.c	\
			ft_strlcat.c		ft_strchr.c			ft_strrchr.c	\
			ft_strncmp.c		ft_strnstr.c		ft_atoi.c		\
			ft_calloc.c			ft_strdup.c			\
			ft_substr.c			ft_strjoin.c		ft_strtrim.c	\
			ft_split.c			ft_itoa.c			ft_strmapi.c	\
			ft_striteri.c		ft_putchar_fd.c		ft_putstr_fd.c	\
			ft_putendl_fd.c		ft_putnbr_fd.c

SRCS_B =	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c	\
        	ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c	\
       		ft_lstclear.c		ft_lstiter.c		ft_lstmap.c

OBJS =		${SRCS:%.c=%.o}

OBJS_B =	${SRCS_B:%.c=%.o}

#D_SRCS = srcs
#D_INC = includes

# ------------------------------------------------------------------------------

#%.o:		${SRCS} ${HDRS}
#			@${CC} ${FLAGS} -c $< -o $@
%.o:		%.c ${HDRS}
			@${CC} ${FLAGS} -c -o $@ $<



${NAME}: 	${OBJS} ${HDRS}
			@${AR} ${NAME} $?
			@${RM} ${OBJS}

all:		${NAME}

clean:
			@${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

bonus:
			@make OBJS="${OBJS_B}" all

#exec:		${SRCS}
#			${CC} ${FLAGS} ${OPTFLAGS} ${SRCS} -o ${ENAME}


# ------------------------------------------------------------------------------

#check:		re


# ------------------------------------------------------------------------------

.PHONY: re all clean fclean .c.o
