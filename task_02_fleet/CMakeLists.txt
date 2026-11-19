cmake_minimum_required(VERSION 3.16)
project(task_02_fleet)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(task_02_fleet
        main.cpp
        Fleet.cpp
        ServiceCenter.cpp
        Things.cpp
        Transport.cpp
)