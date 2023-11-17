project(hadlock_test DESCRIPTION "test method for hadlock library")

# set sources for executable
message("Finding hadlocksource files")
set(HADLOCK_TEST_SOURCES
    test.cpp
)

add_executable(hadlock_test ${HADLOCK_TEST_SOURCES})
target_link_libraries(hadlock_test gtest_main hadlock)
add_test(NAME hadlock_lib_test COMMAND hadlock_test)
