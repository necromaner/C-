#include <gtest/gtest.h>
#include "TreeNode.h"
/*
 * 用c/c++实现平衡二叉树，创建查找插入删除，导出排序数值。
 */


TEST(testCase, build) {
    vector<int> x = {10, 20, 30, 40, 50, 60, 70, 80};
    vector<int> dlr = {40, 20, 10, 30, 60, 50, 70, 80};
    vector<int> ldr = {10, 20, 30, 40, 50, 60, 70, 80};
    vector<int> lrd = {10, 30, 20, 50, 80, 70, 60, 40};
    TreeNode *t = build(x);
    EXPECT_EQ(dlr, DLR(t));
    EXPECT_EQ(ldr, LDR(t));
    EXPECT_EQ(lrd, LRD(t));
}
TEST(testCase, find) {
    vector<int> x = {10, 20, 30, 40, 50, 60, 70, 80};
    TreeNode *t = build(x);
    EXPECT_EQ(true, find(t,10));
    EXPECT_EQ(false, find(t,1));
}
TEST(testCase, insert) {
    vector<int> x = {10, 20, 30, 40, 50, 60, 70, 80};
    vector<int> ldr1 = {10, 20, 30, 40, 50, 60, 70, 80,90};
    vector<int> ldr2 = {1,10, 20, 30, 40, 50, 60, 70, 80,90};
    vector<int> ldr3 = {1,10, 20, 30, 40,45, 50, 60, 70, 80,90};
    vector<int> ldr4 = {1,10, 20, 30, 40,45, 50, 60, 70, 80,90};
    TreeNode *t = build(x);
    insert(t,90);
    EXPECT_EQ(ldr1, LDR(t));
    insert(t,1);
    EXPECT_EQ(ldr2, LDR(t));
    insert(t,45);
    EXPECT_EQ(ldr3, LDR(t));
    insert(t,90);
    EXPECT_EQ(ldr4, LDR(t));
}
TEST(testCase, deleteVal) {
    vector<int> x = {10, 20, 30, 40, 50, 60, 70, 80};
    vector<int> ldr1 = {10, 20, 30, 40, 50, 60, 70, 80,90};
    vector<int> ldr2 = {1,10, 20, 30, 40, 50, 60, 70, 80,90};
    vector<int> ldr3 = {1,10, 20, 30, 40,45, 50, 60, 70, 80,90};
    vector<int> ldr4 = {1,10, 20, 30, 40,45, 50, 60, 70, 80,90};
    TreeNode *t = build(ldr4);
    deleteVal(t,81);
    EXPECT_EQ(ldr3, LDR(t));
    deleteVal(t,45);
    EXPECT_EQ(ldr2, LDR(t));
    deleteVal(t,1);
    EXPECT_EQ(ldr1, LDR(t));
    deleteVal(t,90);
    EXPECT_EQ(x, LDR(t));
}



int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}
//int main() {
//    printf("----------------新建-----------------\n");
//    vector<int> x={10,20,30,40,50,60,70,80};
//    TreeNode *t=build(x);
//    outPut_DLR(t);
//    outPut_LDR(t);
//    outPut_LRD(t);
//    printf("----------------查找-----------------\n");
//    outPut_Find(t,10);
//    outPut_Find(t,11);
//    printf("----------------添加-----------------\n");
//    insert(t,90);
//    outPut_DLR(t);
//    insert(t,90);
//    outPut_DLR(t);
//    insert(t,75);
//    outPut_DLR(t);
//    printf("----------------删除-----------------\n");
//    deleteVal(t,81);
//    outPut_DLR(t);
//    deleteVal(t,80);
//    outPut_DLR(t);
//    deleteVal(t,75);
//    outPut_DLR(t);
//    deleteVal(t,70);
//    outPut_DLR(t);
//    deleteVal(t,70);
//    outPut_DLR(t);
//    printf("----------------end-----------------\n");
//
//
//    return 0;
//}