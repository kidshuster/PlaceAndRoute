#include <gtest/gtest.h>
#include "graph.h"

namespace {
    TEST(Graph,nodes100)
    {
        int size = 100;
        NetToMag::Graph s(size);

        for(int i=0; i<99; i++)
            s.AddEdge(i,i%1,1,i+1,1);
        for(int i=0; i<99; i++)
            EXPECT_EQ(i,s.nodes[i].id);
    }
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Running Graph Tests" << std::endl;
    return RUN_ALL_TESTS();
}
