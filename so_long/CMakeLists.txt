cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long main.c srcs/do_keys.c srcs/start_game.c srcs/make_enem_move.c)

target_link_libraries(so_long /Users/gernesto/Desktop/MyGit/so_long/libmlx.a "-framework OpenGL" "-framework AppKit")