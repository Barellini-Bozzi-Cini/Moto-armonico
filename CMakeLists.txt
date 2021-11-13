cmake_minimum_required(VERSION 3.10)

# set the project name
project(Fisica)

# add the executable
add_executable(Fisica "main.cpp" "io.cpp" "equation_solver.cpp")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)