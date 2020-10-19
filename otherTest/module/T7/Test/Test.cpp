//
// Created by necromaner on 2018/12/13.
//

#include "Test.h"
#include <stdio.h>
Test::Test() {
    printf("-------------test-begin------------\n");
}
Test::~Test() {
    printf("-------------test--end-------------\n");
}
int Test::test(int argc, char ** argv){
    printf("\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // 执行所有的 test case
}