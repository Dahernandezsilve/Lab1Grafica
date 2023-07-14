cmake_minimum_required(VERSION 3.25)
project(Lab1Graficas)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab1Graficas main.cpp color.cpp color.h framebuffer.cpp framebuffer.h vertex2.cpp vertex2.h point.cpp point.h line.cpp line.h polygon.cpp polygon.h fill_polygon.cpp fill_polygon.h)
