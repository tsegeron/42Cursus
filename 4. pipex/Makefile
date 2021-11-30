# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gernesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 23:35:58 by gernesto          #+#    #+#              #
#   Updated: 2021/10/20 06:26:10 by gernesto         ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2

RM = rm -rf
AR = ar rcs

# ------------------------------------------------------------------------------

NAME 	=	libftprintf.a
#ENAME	=	exec

HDRS	=	printft.h

SRCS	=	ft_printf.c			ft_strlen.c			ft_putchar_fd_c.c	\
			ft_itoa.c			ft_itoa_uns.c		ft_itoa_hex.c		\
			ft_toupper.c		check_conv.c		ft_putstr_fd_c.c	\
			zero_struct.c		do_flags.c			do_cases.c			\
			do_case_c.c			do_case_s.c			do_case_p.c			\
			do_case_di.c		do_case_u.c			do_case_x.c			\
			do_case_x_up.c		do_case_perc.c		ft_itoa_lhex.c


#SRCS_B	=

OBJS	=	${SRCS:%.c=%.o}

#OBJS_B	=	${SRCS_B:%.c=%.o}

#DIR		=	sources/
#SUBDIR	=	libft
#D_INC	=	includes

READY	=	Library is assembled
SWEPT	=	Directory was cleaned
_GREEN	=	\e[32m
_YELLOW	=	\e[33m
_CYAN	=	\e[36m
_END	=	\e[0m

# ------------------------------------------------------------------------------

#%.o:		${SRCS} ${HDRS}
#			@${CC} ${FLAGS} -c $< -o $@
%.o:		%.c	${HDRS}
			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<



${NAME}: 	${OBJS}	${HDRS}
#			@${MAKE} -C libft
#			@mv libft/libft.a ${NAME}
			@${AR} ${NAME} $?
			@printf "${_GREEN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS}
#			@${MAKE} -C libft
			@printf "${_YELLOW}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

bonus:		${NAME}



main:
			@${CC} ${FLAGS} ${OPTFLAGS} main.c ${NAME}

test:
			@${CC} ${FLAGS} ${OPTFLAGS} test.c ${NAME}

norm:
			@norminette ${SRCS}


#exec:		${SRCS}
#			${CC} ${FLAGS} ${OPTFLAGS} ${SRCS} -o ${ENAME}


# ------------------------------------------------------------------------------

#check:		re


# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus
