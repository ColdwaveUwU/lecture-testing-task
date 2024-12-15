cmake_minimum_required(VERSION 3.10)
project(stack)

add_library(stack src/stack.c)
add_library(stack::library ALIAS stack)

add_executable(main src/main.c)
target_link_libraries(main PRIVATE stack)

if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(stack PRIVATE -fsanitize=address)
    target_link_options(stack PRIVATE -fsanitize=address)

    target_compile_options(main PRIVATE -fsanitize=address)
    target_link_options(main PRIVATE -fsanitize=address)
endif()

add_subdirectory(test)
enable_testing()

add_subdirectory(benchmark)
