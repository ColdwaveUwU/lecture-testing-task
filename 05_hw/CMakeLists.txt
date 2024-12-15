cmake_minimum_required(VERSION 3.10)
project(stack)

add_library(stack src/stack.c)

add_executable(main src/main.c)
target_link_libraries(main stack)
