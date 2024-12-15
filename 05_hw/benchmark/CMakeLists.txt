cmake_minimum_required(VERSION 3.10)

add_executable(benchmark benchmark.cpp)

target_link_libraries(benchmark PRIVATE stack::library)

if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(benchmark PRIVATE -fsanitize=address)
    target_link_options(benchmark PRIVATE -fsanitize=address)
endif()

target_include_directories(benchmark PRIVATE ${CMAKE_SOURCE_DIR}/src)
