project(forcepart_test DESCRIPTION "test method for forcepart library")

# set sources for executable
message("Finding forcepart_test source files")
set(TEST_SOURCES
    test.cpp
)

add_executable(forcepart_test ${TEST_SOURCES})
target_link_libraries(forcepart_test gtest_main forcepart)
add_test(NAME forcepart_lib_test COMMAND forcepart_test)
