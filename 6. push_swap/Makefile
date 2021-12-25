CC			=	gcc
#-Wall -Wextra -Werror
FLAGS		=
#FLAGS_MLX	=	-framework OpenGL -framework AppKit
OPTFLAGS	=	-O2
#BON_FLG0	=	-D BONUS=0
#BON_FLG1	=	-D BONUS=1

RM			=	rm -rf
AR			=	ar rcs

# ------------------------------------------------------------------------------

NAME 	=	push_swap
NAME_B	=	checker
LIB		=	push_swap.a
#LIB1	=	libft.a
#LIB2	=	so_long.a
#LIB3	=	so_long_b.a

HDRS	=	push_swap.h
#HDRS_B	=	so_long_b.h

FLDR_S	=	srcs/
#FLDR_B	=	srcs_b/
FLDR_H	=	hdrs/

MAIN	=	main.c
MAIN_B	=	checker.c

SRCS	=	libfts/ft_atoi.c			libfts/ft_lstclear.c		libfts/ft_lstnew.c		\
			libfts/ft_split.c			libfts/ft_lstadd_back.c		libfts/ft_lstdelone.c	\
			libfts/ft_lstprelast.c		libfts/ft_strjoin.c			libfts/ft_lstlast.c		\
			libfts/ft_lstadd_front.c	libfts/ft_lstsize.c			libfts/ft_substr.c		\
			libfts/ft_strlen.c			libfts/ft_strncmp.c			libfts/get_next_line.c	\
			libfts/ft_strchr.c																\
			0.merge_sort.c				1.actions.c					2.actions.c				\
			3.actions.c					align_stack_a.c				check_args.c			\
			count_needed_actions.c		fill_stacks.c										\
			gt_set_statuses.c			move_to_b.c					move_to_a.c				\


SRC		=	$(addprefix ${FLDR_S},${SRCS})
#SRCB	=	$(addprefix ${FLDR_B},${SRCS})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
#HDR_B	=	$(addprefix ${FLDR_H},${HDRS_B})
OBJS	=	${SRC:%.c=%.o}
#OBJS_B	=	${SRCB:%.c=%.o}

# ------------------------------------------------------------------------------

READY	=	Push_swap is ready
READYB	=	Checker is ready
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
			@${AR} ${LIB} $?
			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} -o ${NAME}
			@printf "${_GREEN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS}
			@printf "${_YELLOW}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME} ${NAME_B} ${LIB}

re:			fclean all

bonus:		${OBJS}
			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN_B} ${LIB} -o ${NAME_B}
			@printf "${_GREEN}${READYB}${_END}\n"


#main:
#			@${CC} ${FLAGS} ${OPTFLAGS} main.c ${LIB}

#test:
#			@${CC} ${FLAGS} ${OPTFLAGS} test.c ${LIB}

norm:
			@norminette ${MAIN} ${MAIN_B} ${FLDR_H} ${FLDR_S}


#exec:		${SRCS}
#			${CC} ${FLAGS} ${OPTFLAGS} ${SRCS} -o ${ENAME}


# ------------------------------------------------------------------------------

#check:		re


# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus
