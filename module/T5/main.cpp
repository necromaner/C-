#include <gtest/gtest.h>
#include "OutPut/Output.h"
#include "classDemo/classDemo.h"
#include "inheritance/inheritance.h"
#include "operator/operator.h"
#include "learn.h"
TEST(testCase, test0){
    T1 t1;
    EXPECT_EQ(1, t1.t1_1());
}



int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}
