#include <gtest/gtest.h>

TEST(ForcePart, DistanceInt)
{
    EXPECT_EQ(1,1);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    std::cout << "Running ForcePart Tests" << std::endl;
    return RUN_ALL_TESTS();
}
