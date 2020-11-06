#include "../../Test.h"

//#define TT51
//TEST(leetcode,t51) {
//    EXPECT_EQ(,Leetcode().TT51());
//}
#define TT52 totalNQueens
TEST(leetcode,t52) {
    EXPECT_EQ(2,Leetcode().TT52(4));
    EXPECT_EQ(10,Leetcode().TT52(5));
    EXPECT_EQ(4,Leetcode().TT52(6));
    EXPECT_EQ(724,Leetcode().TT52(10));
}
//#define TT53
//TEST(leetcode,t53) {
//    EXPECT_EQ(,Leetcode().TT53());
//}
//#define TT54
//TEST(leetcode,t54) {
//    EXPECT_EQ(,Leetcode().TT54());
//}
//#define TT55
//TEST(leetcode,t55) {
//    EXPECT_EQ(,Leetcode().TT55());
//}
//#define TT56
//TEST(leetcode,t56) {
//    EXPECT_EQ(,Leetcode().TT56());
//}
#define TT57 insert
TEST(leetcode,t57) {
    vector<vector<int>> intervals,ans;
    vector<int> newInterval;
    intervals={{1,3},{6,9}};
    newInterval={2,5};
    ans={{1,5},{6,9}};
    EXPECT_EQ(ans,Leetcode().TT57(intervals,newInterval));
    intervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval={4,8};
    ans={{1,2},{3,10},{12,16}};
    EXPECT_EQ(ans,Leetcode().TT57(intervals,newInterval));
}
//#define TT58
//TEST(leetcode,t58) {
//    EXPECT_EQ(,Leetcode().TT58());
//}
//#define TT59
//TEST(leetcode,t59) {
//    EXPECT_EQ(,Leetcode().TT59());
//}
//#define TT60
//TEST(leetcode,t60) {
//    EXPECT_EQ(,Leetcode().TT60());
//}
//#define TT61
//TEST(leetcode,t61) {
//    EXPECT_EQ(,Leetcode().TT61());
//}
//#define TT62
//TEST(leetcode,t62) {
//    EXPECT_EQ(,Leetcode().TT62());
//}
//#define TT63
//TEST(leetcode,t63) {
//    EXPECT_EQ(,Leetcode().TT63());
//}
#define TT64 minPathSum
TEST(leetcode,t64) {
    vector<vector<int>>grid;
    grid.push_back(vector<int>{1,3,1});
    grid.push_back(vector<int>{1,5,1});
    grid.push_back(vector<int>{4,2,1});
    EXPECT_EQ(Leetcode().TT64(grid), 7);
    grid.clear();
    grid.push_back(vector<int>{1,3,4,8});
    grid.push_back(vector<int>{3,2,2,4});
    grid.push_back(vector<int>{5,7,1,9});
    grid.push_back(vector<int>{2,3,2,3});
    EXPECT_EQ(Leetcode().TT64(grid), 14);
}
#define TT64_1 minPathSum
TEST(leetcode,t64_1) {
    vector<vector<int>>grid;
    grid.push_back(vector<int>{1,3,1});
    grid.push_back(vector<int>{1,5,1});
    grid.push_back(vector<int>{4,2,1});
    EXPECT_EQ(Leetcode().TT64_1(grid), 7);
    grid.clear();
    grid.push_back(vector<int>{1,3,4,8});
    grid.push_back(vector<int>{3,2,2,4});
    grid.push_back(vector<int>{5,7,1,9});
    grid.push_back(vector<int>{2,3,2,3});
    EXPECT_EQ(Leetcode().TT64_1(grid), 14);
}
//#define TT65
//TEST(leetcode,t65) {
//    EXPECT_EQ(,Leetcode().TT65());
//}
//#define TT66
//TEST(leetcode,t66) {
//    EXPECT_EQ(,Leetcode().TT66());
//}
//#define TT67
//TEST(leetcode,t67) {
//    EXPECT_EQ(,Leetcode().TT67());
//}
//#define TT68
//TEST(leetcode,t68) {
//    EXPECT_EQ(,Leetcode().TT68());
//}
//#define TT69
//TEST(leetcode,t69) {
//    EXPECT_EQ(,Leetcode().TT69());
//}
#define TT70_1 climbStairs1
TEST(leetcode,t70_1) {
    int nums;
    int answer;
    int target;

    EXPECT_EQ(Leetcode().TT70_1(-1), 1) << "负数";

    EXPECT_EQ(Leetcode().TT70_1(0), 1) << "0值";

    EXPECT_EQ(Leetcode().TT70_1(1), 1) << "1";
    EXPECT_EQ(Leetcode().TT70_1(2), 2) << "2";
    EXPECT_EQ(Leetcode().TT70_1(3), 3) << "3";
    EXPECT_EQ(Leetcode().TT70_1(4), 5) << "4";
}
#define TT70_2 climbStairs2
TEST(leetcode,t70_2) {
    EXPECT_EQ(Leetcode().TT70_2(-1), 1) << "负数";
    EXPECT_EQ(Leetcode().TT70_2(0), 1) << "0值";
    EXPECT_EQ(Leetcode().TT70_2(1), 1) << "1";
    EXPECT_EQ(Leetcode().TT70_2(2), 2) << "2";
    EXPECT_EQ(Leetcode().TT70_2(3), 3) << "3";
    EXPECT_EQ(Leetcode().TT70_2(4), 5) << "4";
}
//#define TT71
//TEST(leetcode,t71) {
//    EXPECT_EQ(,Leetcode().TT71());
//}
//#define TT72
//TEST(leetcode,t72) {
//    EXPECT_EQ(,Leetcode().TT72());
//}
//#define TT73
//TEST(leetcode,t73) {
//    EXPECT_EQ(,Leetcode().TT73());
//}
//#define TT74
//TEST(leetcode,t74) {
//    EXPECT_EQ(,Leetcode().TT74());
//}
//#define TT75
//TEST(leetcode,t75) {
//    EXPECT_EQ(,Leetcode().TT75());
//}
//#define TT76
//TEST(leetcode,t76) {
//    EXPECT_EQ(,Leetcode().TT76());
//}
//#define TT77
//TEST(leetcode,t77) {
//    EXPECT_EQ(,Leetcode().TT77());
//}
//#define TT78
//TEST(leetcode,t78) {
//    EXPECT_EQ(,Leetcode().TT78());
//}
//#define TT79
//TEST(leetcode,t79) {
//    EXPECT_EQ(,Leetcode().TT79());
//}
//#define TT80
//TEST(leetcode,t80) {
//    EXPECT_EQ(,Leetcode().TT80());
//}
//#define TT81
//TEST(leetcode,t81) {
//    EXPECT_EQ(,Leetcode().TT81());
//}
//#define TT82
//TEST(leetcode,t82) {
//    EXPECT_EQ(,Leetcode().TT82());
//}
#define TT83 deleteDuplicates
TEST(leetcode,t83) {

    ListNode *l1;
    vector<int> l2;
    l1=SetListNode({1,2,3,4});
    l2={1,2,3,4};
    EXPECT_EQ(GetListNode(Leetcode().TT83(l1)),l2 ) << "相同";

    l1=SetListNode({});
    l2={};
    EXPECT_EQ(GetListNode(Leetcode().TT83(l1)),l2 ) << "空";
    l1=SetListNode({1,1,1,2,2,2,3,3,3});
    l2={1,2,3};
    EXPECT_EQ(GetListNode(Leetcode().TT83(l1)),l2 ) << "正常";
}
//#define TT84
//TEST(leetcode,t84) {
//    EXPECT_EQ(,Leetcode().TT84());
//}
//#define TT85
//TEST(leetcode,t85) {
//    EXPECT_EQ(,Leetcode().TT85());
//}
//#define TT86
//TEST(leetcode,t86) {
//    EXPECT_EQ(,Leetcode().TT86());
//}
//#define TT87
//TEST(leetcode,t87) {
//    EXPECT_EQ(,Leetcode().TT87());
//}
//#define TT88
//TEST(leetcode,t88) {
//    EXPECT_EQ(,Leetcode().TT88());
//}
//#define TT89
//TEST(leetcode,t89) {
//    EXPECT_EQ(,Leetcode().TT89());
//}
//#define TT90
//TEST(leetcode,t90) {
//    EXPECT_EQ(,Leetcode().TT90());
//}
//#define TT91
//TEST(leetcode,t91) {
//    EXPECT_EQ(,Leetcode().TT91());
//}
//#define TT92
//TEST(leetcode,t92) {
//    EXPECT_EQ(,Leetcode().TT92());
//}
//#define TT93
//TEST(leetcode,t93) {
//    EXPECT_EQ(,Leetcode().TT93());
//}
#define TT94 inorderTraversal
TEST(leetcode,t94) {
}
#define TT95 numTrees
TEST(leetcode,t95) {
}
#define TT96 numTrees
TEST(leetcode,t96) {
    EXPECT_EQ(42,Leetcode().TT96(5));
}
//#define TT97
//TEST(leetcode,t97) {
//    EXPECT_EQ(,Leetcode().TT97());
//}
//#define TT98
//TEST(leetcode,t98) {
//    EXPECT_EQ(,Leetcode().TT98());
//}
//#define TT99
//TEST(leetcode,t99) {
//    EXPECT_EQ(,Leetcode().TT99());
//}
#define TT100 isSameTree
TEST(leetcode,t100) {
    TreeNode *p1=SetTreeNode("[1,2,3,4]");
    TreeNode *p2=SetTreeNode("[1,2,3,4]");
    EXPECT_EQ(Leetcode().TT100(p1,p2),true ) << "相同";
}




