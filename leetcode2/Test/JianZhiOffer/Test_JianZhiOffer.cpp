#include "../Test.h"

#define TT1 minArray
TEST(JianZhiOffer,t1) {
    vector<int> nums;
    nums = {3,4,5,1,2};
    EXPECT_EQ(JianZhiOffer().TT1(nums), 1);
    nums = {2,2,2,0,1};
    EXPECT_EQ(JianZhiOffer().TT1(nums), 0);
}