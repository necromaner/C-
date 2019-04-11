//
// Created by necromaner on 2019-01-27.
//

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

TEST(BinaryTree,outPut){
    BinaryTree binaryTree;
    TreeNode *t1=new TreeNode(1);
    TreeNode *t2=new TreeNode(2);
    TreeNode *t3=new TreeNode(3);
    TreeNode *t4=new TreeNode(4);
    TreeNode *t5=new TreeNode(5);
    TreeNode *t6=new TreeNode(6);
    TreeNode *t7=new TreeNode(7);
    TreeNode *t8=new TreeNode(8);
    TreeNode *t9=new TreeNode(9);
    t1->left=t2;
    t1->right=t3;
    t2->left=t4;
    t2->right=t5;
    t3->left=t6;
    t3->right=t7;
    t6->right=t8;
    t7->right=t9;
    binaryTree.outPut_DLR(t1);
    binaryTree.outPut_LDR(t1);
    binaryTree.outPut_LRD(t1);
}
TEST(BinaryTree,vector){
    BinaryTree binaryTree;
    vector<int> x={-11,2,3};
    EXPECT_EQ("[-11,  2,  3]",binaryTree.outPut(x));
    x.push_back(1);
    EXPECT_EQ("[-11,  2,  3,  1]",binaryTree.outPut(x));
    map<int,vector<int>> y;
}
TEST(ColumnOutput,vector){
    ColumnOutput columnOutput;
    TreeNode *t1=new TreeNode(1);
    TreeNode *t2=new TreeNode(2);
    TreeNode *t3=new TreeNode(3);
    TreeNode *t4=new TreeNode(4);
    TreeNode *t5=new TreeNode(5);
    TreeNode *t6=new TreeNode(6);
    TreeNode *t7=new TreeNode(7);
    TreeNode *t8=new TreeNode(8);
    TreeNode *t9=new TreeNode(9);
    t1->left=t2;
    t1->right=t3;
    t2->left=t4;
    t2->right=t5;
    t3->left=t6;
    t3->right=t7;
    t6->right=t8;
    t7->right=t9;
    columnOutput.outPut_DLR(t1);
}

TEST(ColumnOutput,outPut_map){
    ColumnOutput columnOutput;
    map<int, vector<int>> x;
    x[-1]={1,2,3};
    x[2]={1,2,3,4};
    x[0]={2,3};
    columnOutput.outPut(x);
}
TEST(ColumnOutput,Column_DLR){
    ColumnOutput columnOutput;
    TreeNode *t1=new TreeNode(1);
    TreeNode *t2=new TreeNode(2);
    TreeNode *t3=new TreeNode(3);
    TreeNode *t4=new TreeNode(4);
    TreeNode *t5=new TreeNode(5);
    TreeNode *t6=new TreeNode(6);
    TreeNode *t7=new TreeNode(7);
    TreeNode *t8=new TreeNode(8);
    TreeNode *t9=new TreeNode(9);
    t1->left=t2;
    t1->right=t3;
    t2->left=t4;
    t2->right=t5;
    t3->left=t6;
    t3->right=t7;
    t6->right=t8;
    t7->right=t9;
    bool x=t7->left;
    printf("%d\n",x);
//    columnOutput.outPut_DLR(t1);
//    columnOutput.outPut_LDR(t1);
//    columnOutput.outPut_LRD(t1);
//    columnOutput.outputColumn_DLR(t1);
//    printf("\n");
//    columnOutput.outputColumn_LDR(t1);
//    printf("\n");
//    columnOutput.outputColumn_LRD(t1);


}

TEST(ColumnOutput,DLR) {
    ColumnOutput columnOutput;
//    vector<int> x={1,2,3,4,5,6,7};
//    vector<int> D(x.begin(),x.begin()+1);
//    printf("%s\n",columnOutput.outPut(D).c_str());

    vector<int> DLR = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> LDR = {2, 4, 3, 5, 1, 6, 8, 7};
    vector<int> LRD = {4, 5, 3, 2, 8, 7, 6, 1};
    int i = 4;
    vector<int> DLR1(DLR.begin()+1,DLR.begin()+1+i);
    vector<int> DLR2(DLR.begin()+1+i,DLR.end());
    vector<int> LDR1(LDR.begin(),LDR.begin()+i);
    vector<int> LDR2(LDR.begin()+1+i,LDR.end());
    printf("%s\n",columnOutput.outPut(DLR1).c_str());
    printf("%s\n",columnOutput.outPut(DLR2).c_str());
    printf("%s\n",columnOutput.outPut(LDR1).c_str());
    printf("%s\n",columnOutput.outPut(LDR2).c_str());

    vector<int> LDR3(LDR.begin(), LDR.begin() + i);
    vector<int> LDR4(LDR.begin() + 1 + i, LDR.end());
    vector<int> LRD1(LRD.begin(), LRD.begin() + i);
    vector<int> LRD2(LRD.begin() + i, LRD.end() - 1);;
    printf("%s\n", columnOutput.outPut(LDR3).c_str());
    printf("%s\n", columnOutput.outPut(LDR4).c_str());
    printf("%s\n", columnOutput.outPut(LRD1).c_str());
    printf("%s\n", columnOutput.outPut(LRD2).c_str());
}

TEST(BinaryTree,inPut) {
    BinaryTree binaryTree;
    vector<int> DLR = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> LDR = {2, 4, 3, 5, 1, 6, 8, 7};
    vector<int> LRD = {4, 5, 3, 2, 8, 7, 6, 1};
    binaryTree.outPut_DLR(binaryTree.inPut_DLR_LDR(DLR, LDR));
    binaryTree.outPut_LDR(binaryTree.inPut_DLR_LDR(DLR, LDR));
    binaryTree.outPut_LRD(binaryTree.inPut_DLR_LDR(DLR, LDR));
    printf("\n");
    binaryTree.outPut_DLR(binaryTree.inPut_LDR_LRD(LDR, LRD));
    binaryTree.outPut_LDR(binaryTree.inPut_LDR_LRD(LDR, LRD));
    binaryTree.outPut_LRD(binaryTree.inPut_LDR_LRD(LDR, LRD));


    ColumnOutput columnOutput;
    vector<int> DLR1 = {1,2,4,5,3,6,8,7,9};
    vector<int> LDR1 = {4,2,5,1,6,8,3,7,9};
    vector<int> LRD1 = {4,5,2,8,6,9,7,3,1};

    columnOutput.outputColumn_DLR(columnOutput.inPut_DLR_LDR(DLR, LDR));
    printf("\n");
    columnOutput.outputColumn_LDR(columnOutput.inPut_DLR_LDR(DLR, LDR));
    printf("\n");
    columnOutput.outputColumn_LRD(columnOutput.inPut_DLR_LDR(DLR, LDR));
    printf("---------------------\n");
    columnOutput.outputColumn_DLR(columnOutput.inPut_LDR_LRD(DLR, LDR));
    printf("\n");
    columnOutput.outputColumn_LDR(columnOutput.inPut_LDR_LRD(DLR, LDR));
    printf("\n");
    columnOutput.outputColumn_LRD(columnOutput.inPut_LDR_LRD(DLR, LDR));
}

TEST(BinaryTree,findTilt) {
    BinaryTree binaryTree;
    TreeNode *t1=new TreeNode(1);
    TreeNode *t2=new TreeNode(2);
    TreeNode *t3=new TreeNode(3);
    TreeNode *t4=new TreeNode(4);
    TreeNode *t5=new TreeNode(5);
    TreeNode *t6=new TreeNode(6);
    TreeNode *t7=new TreeNode(7);
    TreeNode *t8=new TreeNode(8);
    TreeNode *t9=new TreeNode(9);

    t1->left=t2;
    t1->right=t3;
    t2->left=t4;

    EXPECT_EQ(1,binaryTree.findTilt(t1));
}