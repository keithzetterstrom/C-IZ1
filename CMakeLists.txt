cmake_minimum_required(VERSION 3.15)
project(iz1 C)
set(CMAKE_C_STANDARD 99)
enable_testing()
add_subdirectory(tests)

add_executable(iz1 src/main.c src/matrix_work.c include/matrix_work.h)
add_test(NAME unit_test COMMAND test_m)