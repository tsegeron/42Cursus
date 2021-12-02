cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long main.c)

target_link_libraries(so_long /Users/gernesto/Desktop/so_long/libmlx.a "-framework OpenGL" "-framework AppKit")