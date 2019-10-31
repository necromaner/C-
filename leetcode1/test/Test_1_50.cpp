#include "Test.h"

#define TT1 twoSum
TEST(leetcode,t1) {
    vector<int> nums;
    vector<int> a1;
    int target;

    nums={2,7,11,15};
    a1={0,1};
    target=9;
    EXPECT_EQ(Solution().TT1(nums,target), a1) << "默认";

    nums={0,4,3,0};
    a1={0,3};
    target=0;
    EXPECT_EQ(Solution().TT1(nums,target), a1) << "0值";

    nums={-1,-2,-3,-4,-5};
    a1={2,4};
    target=-8;
    EXPECT_EQ(Solution().TT1(nums,target), a1) << "负值";
}
#define TT2 addTwoNumbers
TEST(leetcode,t2) {
//    ListNode *l1;
//    ListNode *l2;
//    ListNode *l3;
//    l1=Solution().SetListNode({2,4,3});
//    l2=Solution().SetListNode({5,6,4});
//    l3=Solution().SetListNode({8,0,7});
//    EXPECT_EQ(Solution().GetListNode(Solution().TT2(l1,l2)), Solution().GetListNode(l3)) << "默认";
}
#define TT3 reverse
TEST(leetcode,t3) {
    EXPECT_EQ(Solution().TT3(123),321) << "默认";
    EXPECT_EQ(Solution().TT3(-123),-321) << "负数";
}
#define TT14 longestCommonPrefix
TEST(leetcode,t14) {
    vector<string> strs;
    string answer;
    strs={"flower","flow","flight"};
    answer="fl";
    EXPECT_EQ(Solution().TT14(strs),answer) << "默认";
    strs={"dog","racecar","car"};
    answer="";
    EXPECT_EQ(Solution().TT14(strs),answer) << "无";
    strs={"",""};
    answer="";
    EXPECT_EQ(Solution().TT14(strs),answer) << "无";
}



