cmake_minimum_required(VERSION 3.0)
project(main_call DESCRIPTION "main function for graph partitioning project")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Finding main application call")
include_directories(include)
message("Include directories linked")
add_library(main_call src/main.cpp)
message("Built Main application call")
