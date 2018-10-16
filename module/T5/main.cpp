#include <gtest/gtest.h>
#include "Output.h"
#include "learn.h"
TEST(testCase, test0){
    EXPECT_EQ(1, t1_1());
}
int main(int argc, char ** argv) {
    Circle circle(3);
    outPut(circle.Area());
    
    
    Time time1(10,1);
    time1.show();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}