#include <gtest/gtest.h>
#include "Output.h"
#include "learn.h"
TEST(testCase, test0){
    EXPECT_EQ(14, t1_1());
}
int main(int argc, char ** argv) {
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}