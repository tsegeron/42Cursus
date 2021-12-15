cmake_minimum_required(VERSION 3.20)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap
        srcs/libfts/ft_atoi.c
        srcs/libfts/ft_lstadd_back.c
        srcs/libfts/ft_lstadd_front.c
        srcs/libfts/ft_lstclear.c
        srcs/libfts/ft_lstdelone.c
        srcs/libfts/ft_lstlast.c
        srcs/libfts/ft_lstnew.c
        srcs/libfts/ft_lstprelast.c
        srcs/libfts/ft_lstsize.c
#        main.c
        srcs/test1.c
        srcs/check_args.c
        srcs/0.merge_sort.c
        srcs/1.actions.c
        srcs/2.actions.c
        srcs/3.actions.c
        srcs/do_magic.c
        srcs/do_stuff.c
        srcs/fill_stacks.c
        srcs/count_needed_actions.c)
