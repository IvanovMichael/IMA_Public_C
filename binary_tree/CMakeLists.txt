cmake_minimum_required(VERSION 3.10)
project(binary_tree C)

set(CMAKE_C_STANDARD 11)

add_executable(binary_tree main.c tree.h tree.c)