# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.0)

# Project's name
project(parprog DESCRIPTION "full circuit placement")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Download and unpack googletest at configure time
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/gtest/CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .  RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
include(CTest)

# set int main sources for executable mode
message("Finding source files")
set(SOURCES
    ../src/app/src/main.cpp
)

# add executable for the SOURCES variable
message("Creating Executable")
add_executable(parprog ${SOURCES})
message("Moving Executable to ${CMAKE_BINARY_DIR}/../")
set_target_properties(parprog PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../")

# link libraries
message("Adding subdirectories")
add_subdirectory(../src/libs/graph)
add_subdirectory(../src/libs/forcepart)
add_subdirectory(../src/libs/hadlock)
message("Linking libraries from subdirectories")
target_link_libraries(parprog forcepart)
target_link_libraries(parprog hadlock)

# set include directories
message("linking include directoreis")
target_include_directories(parprog 
    PRIVATE 
        ../src/app/include
)

message("")
message("Build completed")
message("")
