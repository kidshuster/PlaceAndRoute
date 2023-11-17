cmake_minimum_required(VERSION 3.0)
project(hadlock_lib DESCRIPTION "partitioning library using graph library as dependency")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Creating hadlock library")
add_library(hadlock src/hadlock.cpp)
message(STATUS "Linking hadlock include directories")
target_include_directories(hadlock PUBLIC include)
message(STATUS "linking graph library")
target_link_libraries(hadlock graph)

# create test modules
message(STATUS "Creating Hadlock test")
add_subdirectory(test)
message(STATUS "Adding tests")

message(STATUS "Hadlock library build completed")
