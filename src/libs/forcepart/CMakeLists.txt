cmake_minimum_required(VERSION 3.0)
project(forcepart_lib DESCRIPTION "partitioning library using graph library as dependency")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Creating forcepart library")
add_library(forcepart src/forcepart.cpp)
message(STATUS "Linking forcepart include directories")
target_include_directories(forcepart PUBLIC include)
message(STATUS "linking graph library")
target_link_libraries(forcepart graph)

# create test modules
message(STATUS "Creating ForcePart test")
add_subdirectory(test)
message(STATUS "Adding tests")

message(STATUS "ForcePart library build completed")
