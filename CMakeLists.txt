cmake_minimum_required(VERSION 3.6)
project(lab2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c linked_list.h)
add_executable(lab2 ${SOURCE_FILES} linked_list.h)