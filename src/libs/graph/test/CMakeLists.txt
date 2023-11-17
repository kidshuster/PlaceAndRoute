project(graph_test DESCRIPTION "test method for graph library")

# set sources for executable
message("Finding graph_test source files")
set(GRAPH_TEST_SOURCES
    test.cpp
)

add_executable(graph_test ${GRAPH_TEST_SOURCES})
target_link_libraries(graph_test gtest_main graph)
add_test(NAME graph_lib_test COMMAND graph_test)
