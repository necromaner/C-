#include "Test.h"
Test::Test() {
    printf("-------------test-begin------------\n");
}
Test::~Test() {
    printf("-------------test--end-------------\n");
}
int Test::test(int argc, char ** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // 执行所有的 test case
}

TEST(APP_dev,T1){
    M1 m1;
    m1.T1();
}
TEST(APP_dev,T2){
    M1 m1;
    m1.T2();
}
TEST(APP_dev,T3){
    M1 m1;
    m1.T3();
}
TEST(APP_dev,T4){
    M1 m1;
    for (int j = 0; j < 2000; ++j) {
        printf("  %5d  |",j);
    }
    printf("\n");
    m1.T4(0);
    m1.T4(-100);
    m1.T4(-200);
    m1.T4(-300);
    m1.T4(100);
    m1.T4(200);
    m1.T4(300);
}

TEST(APP_dev,T5){
    M1 m1;
    m1.T5();
}