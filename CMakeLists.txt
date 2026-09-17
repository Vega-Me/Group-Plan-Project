
cmake_minimum_required(VERSION 3.16)
project(StudyLoadPlanner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(StudyPlanner
    src/main.cpp
    src/Assignment.cpp
    src/StudyPlanner.cpp
    src/input_utils.cpp
)

target_include_directories(StudyPlanner PRIVATE include)