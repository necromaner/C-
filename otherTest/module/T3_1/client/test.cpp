#include <gtest/gtest.h>
#include <iostream>
int Add(int a, int b) {
    return a+b;
}

TEST(testCase, test0){
    EXPECT_EQ(14, Add(4, 10));
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}