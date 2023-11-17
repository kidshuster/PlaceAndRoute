cmake_minimum_required(VERSION 3.0)
project(graph_lib DESCRIPTION "graph library with weighted and unweighted edges. has internal node and edge vectors")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Creating graph library")
add_library(graph SHARED src/graph.cpp)
message(STATUS "Linking graph include directories")
target_include_directories(graph PUBLIC include)

# create test modules
message(STATUS "Creating Graph_test")
add_subdirectory(test)
message(STATUS "Adding tests")

message(STATUS "Graph library build completed")
