CC			=	gcc
#-Wall -Wextra -Werror
FLAGS		=	-Wall -Wextra -Werror
#FLAGS_MLX	=	-framework OpenGL -framework AppKit
OPTFLAGS	=	-O2
#BON_FLG0	=	-D BONUS=0
#BON_FLG1	=	-D BONUS=1

RM			=	rm -rf
AR			=	ar rcs

# ------------------------------------------------------------------------------

NAME 	=	philo
NAME_B 	=	philo_bonus
LIB		=	philo.a
LIB_B	=	philo_bonus.a

HDRS	=	philo.h
#HDRS_B	=

FLDR_S	=	srcs/
FLDR_H	=	hdrs/

FLDR_SB	=	srcs_b/
FLDR_HB	=	hdrs_b/

MAIN_F	=	main.c
MAIN_FB	=	main_b.c

SRCS	=	libfts/ft_atoi.c		libfts/ft_calloc.c		libfts/ft_bzero.c			\
			libfts/ft_strjoin.c		libfts/ft_strlen.c		libfts/ft_lstadd_back.c		\
			libfts/ft_lstnew.c		libfts/ft_lstlast.c									\
			init.c					parse_input.c			philos_routine.c			\
			time_stuff.c			write_actions.c			at_exit.c					\


SRCS_B	=	libfts/ft_atoi.c		libfts/ft_calloc.c		libfts/ft_bzero.c			\
			libfts/ft_strjoin.c		libfts/ft_strlen.c		libfts/ft_lstadd_back.c		\
			libfts/ft_lstnew.c		libfts/ft_lstlast.c									\
			init.c					parse_input.c			philos_routine.c			\
			time_stuff.c			write_actions.c			at_exit.c					\


SRC		=	$(addprefix mandatory/, $(addprefix ${FLDR_S},${SRCS}))
HDR		=	$(addprefix mandatory/, $(addprefix ${FLDR_H},${HDRS}))
OBJS	=	${SRC:%.c=%.o}
MAIN	=	$(addprefix mandatory/, ${MAIN_F})

SRC_B	=	$(addprefix bonus_/, $(addprefix ${FLDR_SB},${SRCS_B}))
HDR_B	=	$(addprefix bonus_/, $(addprefix ${FLDR_HB},${HDRS}))
OBJS_B	=	${SRC_B:%.c=%.o}
MAIN_B	=	$(addprefix bonus_/, ${MAIN_FB})

# ------------------------------------------------------------------------------

READY	=	Philo is ready
READY_B	=	Philo_bonus is ready
SWEPT	=	Directory was cleaned
_GREEN	=	\e[32m
_YELLOW	=	\e[33m
_CYAN	=	\e[0;36m
_PURPLE	=	\e[0;35m
_END	=	\e[0m

# ------------------------------------------------------------------------------

#%.o:		${SRCS} ${HDRS}
#			@${CC} ${FLAGS} -c $< -o $@
%.o:		%.c	${HDR}
			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<


${NAME}: 	${OBJS} ${MAIN}
			@${AR} ${LIB} $?
			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} -o ${NAME}
#			@${MAKE} clean
			@printf "${_CYAN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS} ${OBJS_B} ${LIB} ${LIB_B}
			@printf "${_PURPLE}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME} ${NAME_B}

re:			fclean all

bonus:		${OBJS_B} ${MAIN_B}
			@${AR} ${LIB_B} $?
			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN_B} ${LIB_B} -o ${NAME_B}
#			@${MAKE} clean
			@printf "${_CYAN}${READY_B}${_END}\n"


norm:
			@norminette ${MAIN} ${HDR} ${SRC} ${MAIN_B} ${HDR_B} ${SRC_B}



# ------------------------------------------------------------------------------



# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus
