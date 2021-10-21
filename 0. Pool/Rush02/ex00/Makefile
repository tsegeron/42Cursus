# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gernesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 23:38:11 by gernesto          #+#    #+#              #
#    Updated: 2021/08/07 16:51:28 by gernesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2

RM = rm -rf
AR = ar rcs

# ------------------------------------------------------------------------------

NAME = rush-02

SRCS = main.c check_divmod_0.c check_operator.c ft_atoi.c print_result.c
OBJS = ${SRCS:.c=.o}

#D_SRCS = srcs
#D_INC = includes

# ------------------------------------------------------------------------------

.c.o:
			${CC} ${FLAGS} ${OPTFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${SRCS}
			${CC} ${FLAGS} ${OPTFLAGS} ${SRCS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

# ------------------------------------------------------------------------------

check:		re
			@echo "I'm checking content of the file" > 1not_empty
			@touch 2empty
			@mkdir 3dir
			./${NAME} || true;
			./${NAME} par1 || true;
			./${NAME} par1 par2 || true;
			./${NAME} 1not_empty || true;
			./${NAME} 2empty || true;
			./${NAME} 3dir || true;
			@${RM} 1not_empty 2empty 3dir

# ------------------------------------------------------------------------------

.PHONY: re all clean fclean .c.o check
