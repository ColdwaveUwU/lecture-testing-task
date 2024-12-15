cmake_minimum_required(VERSION 3.12) # Минимальная версия CMake
project(tests) # Название проекта

include(FetchContent) # Включаем поддержку загрузки контента

# Загрузка и настройка googletest через FetchContent
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git # Репозиторий googletest
    GIT_TAG v1.15.2 # Тег версии googletest
    OVERRIDE_FIND_PACKAGE # Ожидаем, что googletest не будет найден локально
)

FetchContent_MakeAvailable(googletest) # Загружаем googletest

# Для Windows: заставляем использовать общий CRT для библиотеки googletest
if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Создаем исполнимый файл для тестов, добавляя тестовые файлы и исходники стека
add_executable(tests
    test_stack.cpp # Тесты стека
    test_smoke.cpp # Тесты для проверки работоспособности
    ../src/stack.c # Исходный файл стека
)

# Указываем директории с заголовочными файлами для тестов
target_include_directories(tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src # Директория с исходниками (stack.h и другие)
    ${CMAKE_SOURCE_DIR}/test # Директория с тестами (например, stack_fixture.h)
)

# Линкуем googletest к исполнимому файлу тестов
target_link_libraries(tests PRIVATE gtest gtest_main)

# Настройка для покрытия кода в режиме Debug (если используется Clang)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        # Включаем опции для покрытия кода
        target_compile_options(tests PRIVATE -coverage -fprofile-instr-generate -fcoverage-mapping)
        target_link_options(tests PRIVATE -coverage)

        # Очищаем файлы gcda после выполнения тестов
        execute_process(COMMAND rm -f *.gcda WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/tests.dir)
    endif()
endif()
