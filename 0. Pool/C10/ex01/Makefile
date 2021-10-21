# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gernesto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/03 07:00:41 by gernesto          #+#    #+#              #
#    Updated: 2021/08/03 07:00:43 by gernesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror
OPTFLAGS = -O2

RM = rm -rf
AR = ar rcs

# ------------------------------------------------------------------------------

NAME = ft_cat

SRCS = main.c 
OBJS = ${SRCS:.c=.o}

#D_SRCS = srcs
#D_INC = includes

# ------------------------------------------------------------------------------

.c.o:
			${CC} ${FLAGS} ${OPTFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
			${CC} ${FLAGS} ${OPTFLAGS} ${OBJS} -o ${NAME}

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
