cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap
        srcs/actions.c
        srcs/check_args.c
        srcs/ft_atoi.c
        srcs/ft_lstadd_back.c
        srcs/ft_lstlast.c
        srcs/ft_lstnew.c
        srcs/ft_lstsize.c
#        srcs/main.c
        srcs/merge_sort.c
#        srcs/test.c
        srcs/test1.c
        )
