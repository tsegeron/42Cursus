CC			=	gcc
#-Wall -Wextra -Werror
FLAGS		=
FLAGS_MLX	=	-framework OpenGL -framework AppKit
OPTFLAGS	=	-O2
#BON_FLG0	=	-D BONUS=0
BON_FLG1	=	-D BONUS=1

RM			=	rm -rf
AR			=	ar rcs

# ------------------------------------------------------------------------------

NAME 	=	so_long
NAME_B	=	so_long_bonus
LIB		=	libmlx.a
LIB1	=	libft.a
LIB2	=	so_long.a
LIB3	=	so_long_b.a

HDRS	=	so_long.h
HDRS_B	=	so_long_b.h

FLDR_S	=	srcs/
FLDR_B	=	srcs_b/
FLDR_H	=	hdrs/

MAIN	=	main.c

SRCS	=	read_map.c		check_symbols.c		map_dimensions.c	\
			mlx_stuff.c		do_keys.c			make_enem_move.c	\
			start_game.c	draw_map.c			game_stuff.c		\


SRC		=	$(addprefix ${FLDR_S},${SRCS})
SRCB	=	$(addprefix ${FLDR_B},${SRCS})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
HDR_B	=	$(addprefix ${FLDR_H},${HDRS_B})
OBJS	=	${SRC:%.c=%.o}
OBJS_B	=	${SRCB:%.c=%.o}

# ------------------------------------------------------------------------------

READY	=	So_long ready to be launched
READYB	=	So_long_bonus ready to be launched
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


${NAME}: 	${OBJS}
			@${MAKE} -C mlx
			@cp mlx/libmlx.a ${LIB}
			@${MAKE} -C libft
			@cp libft/libft.a ${LIB1}
			@${AR} ${LIB2} $?
#			@${RM} ${OBJS}
#			@${MAKE} clean -C mlx
			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} ${LIB1} ${LIB2} -o ${NAME}
#			@${RM} ${OBJS} ${LIB} ${LIB1} ${LIB2}
			@printf "${_GREEN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${MAKE} fclean -C libft
			@${MAKE} clean -C mlx
			@${RM} ${OBJS} ${OBJS_B} ${LIB} ${LIB1} ${LIB2} ${LIB3} mlx/libmlx.a
			@printf "${_YELLOW}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME} ${NAME_B}

re:			fclean all

bonus:		${OBJS_B}
			@${MAKE} -C mlx
			@cp mlx/libmlx.a ${LIB}
			@${MAKE} -C libft
			@cp libft/libft.a ${LIB1}
			@${AR} ${LIB3} $?
#			@${RM} ${OBJS_B}
#			@${MAKE} clean -C mlx
			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} ${LIB1} ${LIB3} -o ${NAME_B}
#			@${RM} ${OBJS_B} ${LIB} ${LIB1} ${LIB3}
			@printf "${_GREEN}${READYB}${_END}\n"


#main:
#			@${CC} ${FLAGS} ${OPTFLAGS} main.c ${LIB}

#test:
#			@${CC} ${FLAGS} ${OPTFLAGS} test.c ${LIB}

norm:
			@norminette ${MAIN} ${FLDR_H} ${FLDR_S} ${FLDR_B} libft


#exec:		${SRCS}
#			${CC} ${FLAGS} ${OPTFLAGS} ${SRCS} -o ${ENAME}


# ------------------------------------------------------------------------------

#check:		re


# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus
