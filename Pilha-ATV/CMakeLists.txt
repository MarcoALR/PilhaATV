cmake_minimum_required(VERSION 3.25)
project(PilhaDinamica)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PilhaDinamica
        main.cpp
        Pilha.cpp
        Pilha.h)
