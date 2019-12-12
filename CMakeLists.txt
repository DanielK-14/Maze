cmake_minimum_required(VERSION 3.15)
project(MazeProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MazeProject
               main.cpp
               Maze.cpp
               Maze.h
               Stack.cpp
               Stack.h
               Queue.h
               Queue.cpp
               Point.h)