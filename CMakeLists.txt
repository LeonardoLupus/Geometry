cmake_minimum_required(VERSION 3.23)
project(Geometry)

set(CMAKE_CXX_STANDARD 20)

add_executable(Geometry main.cpp  Point2D.cpp Point2D.h Angel.cpp Angel.h
        Vector2D.cpp
        Vector2D.h)
