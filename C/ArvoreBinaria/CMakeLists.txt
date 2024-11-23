cmake_minimum_required(VERSION 3.29)

set(CMAKE_C_STANDARD 11)

project(arvorebinaria C)

add_executable(arvorebinaria
    main.c
    arvorebinaria.c
    arvorebinaria.h
    comparadores.c
    comparadores.h
    printers.c
    printers.h
    )
