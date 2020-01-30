cmake_minimum_required(VERSION 3.13)
project(Dijkstra C)

set(CMAKE_C_STANDARD 99)

add_executable(Dijkstra main.c graph.c graph.h queue.c queue.h)