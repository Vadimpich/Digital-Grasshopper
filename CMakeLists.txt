cmake_minimum_required(VERSION 3.24)
project(Digital_Grasshopper)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Digital_Grasshopper
        main.cpp Game.cpp Game.h GameParams.cpp GameParams.h)
