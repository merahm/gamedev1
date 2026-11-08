cmake_minimum_required(VERSION 4.3)
project(game C)

set(CMAKE_C_STANDARD 11)

add_executable(game main.c
        heads/camera.h
        heads/window.h
        heads/debug_grid.h
        heads/cam_movement.h
        heads/player_position.h)   # your actual source files

target_include_directories(game PRIVATE /usr/local/include)
target_link_directories(game PRIVATE /usr/local/lib)
target_link_libraries(game PRIVATE raylib m)
