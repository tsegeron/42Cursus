cmake_minimum_required(VERSION 3.20)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers
        main.c
        srcs/libfts/ft_atoi.c
        srcs/input_parsing.c srcs/initialization.c srcs/philos_routine.c)
