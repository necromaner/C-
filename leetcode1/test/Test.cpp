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




TEST(ListNode,SetListNode){
    vector<int> list;
    ListNode *setList;
    list={1,2,3,4};
    setList = Solution().SetListNode(list);
    EXPECT_EQ(list, Solution().GetListNode(setList));
    list.clear();

    list={1};
    setList = Solution().SetListNode(list);
    EXPECT_EQ(list, Solution().GetListNode(setList));

    list={};
    setList = Solution().SetListNode(list);
    EXPECT_EQ(list, Solution().GetListNode(setList));
}

