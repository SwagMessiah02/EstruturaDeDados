cmake_minimum_required(VERSION 3.29)
project(Testec C)

set(CMAKE_C_STANDARD 11)

add_executable(Testec main.c
        arvorebinaria.h
        arvorebinaria.c
        comparators.c
        comparators.h
        printers.c
        printers.h)
