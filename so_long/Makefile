CC = gcc

FLAGS =
OPTFLAGS = -O2

RM = rm -rf
AR = ar rcs

# ------------------------------------------------------------------------------

NAME 	=	libmlx.a
#ENAME	=	exec

HDRS	=	so_long.h

FLDR_S	=	srcs/
FLDR_H	=	hdrs/
FLDR_B	=	srcs_b/

SRCS	=	read_map.c		check_symbols.c		map_dimensions.c	\
			mlx_stuff.c		do_keys.c


SRCS_B	=

SRC		=	$(addprefix ${FLDR_S},${SRCS})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
SRC_B	=	$(addprefix ${FLDR_B},${SRCS_B})

OBJS	=	${SRC:%.c=%.o}
OBJS_B	=	${SRC_B:%.c=%.o}

# ------------------------------------------------------------------------------

READY	=	Library is assembled
SWEPT	=	Directory was cleaned
_GREEN	=	\e[32m
_YELLOW	=	\e[33m
_CYAN	=	\e[36m
_END	=	\e[0m

# ------------------------------------------------------------------------------

#%.o:		${SRCS} ${HDRS}
#			@${CC} ${FLAGS} -c $< -o $@
%.o:		%.c	${HDR}
			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<



${NAME}: 	${OBJS}	${HDR}
			@${MAKE} -C libft
			@mv libft/libft.a ${NAME}
			@${AR} ${NAME} $?
			@${RM} ${OBJS}
			@${MAKE} -C mlx
#			@mv mlx/libmlx.a .
			@${MAKE} clean -C mlx
			@printf "${_GREEN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS}
			@printf "${_YELLOW}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

#bonus:		${NAME}



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
