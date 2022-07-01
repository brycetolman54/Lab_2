cmake_minimum_required(VERSION 3.21)
project(NavigationLabCode_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Lab2_NavigationCode)

add_executable(NavigationLabCode_1
        Lab2_NavigationCode/graphicsStuff.cpp
        Lab2_NavigationCode/main.cpp
        Lab2_NavigationCode/NavigationInterface.h)
