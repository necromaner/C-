#include "../Test.h"

#define TT01_1 isUnique
TEST(CTIC,t01_1) {
    EXPECT_EQ(false, CTCI().TT01_1("leetcode"));
    EXPECT_EQ(true, CTCI().TT01_1("abc"));
}
#define TT01_2 CheckPermutation
TEST(CTIC,t01_2) {
    EXPECT_EQ(true, CTCI().TT01_2("abc", "bca"));
    EXPECT_EQ(false, CTCI().TT01_2("abc", "bad"));
}
#define TT01_3 replaceSpaces
TEST(CTIC,t01_3) {
    EXPECT_EQ("Mr%20John%20Smith",CTCI().TT01_3("Mr John Smith    ",13));
    EXPECT_EQ("%20%20%20%20%20",CTCI().TT01_3("               ",5));
}
#define TT01_4 canPermutePalindrome
TEST(CTIC,t01_4) {
    EXPECT_EQ(true,CTCI().TT01_4("tactcoa"));
    EXPECT_EQ(true,CTCI().TT01_4("aaa"));
    EXPECT_EQ(false,CTCI().TT01_4("code"));
}
#define TT01_5 oneEditAway
TEST(CTIC,t01_5) {
    EXPECT_EQ(true,CTCI().TT01_5("pale","ple"));
    EXPECT_EQ(false,CTCI().TT01_5("pales","pal"));
}
//#define TT01_6 compressString
//TEST(CTIC,t01_6) {
//    EXPECT_EQ(CTCI().TT01_6());
//}
//#define TT01_7 rotate
//TEST(CTIC,t01_7) {
//    EXPECT_EQ(CTCI().TT01_7());
//}
//#define TT01_8 setZeroes
//TEST(CTIC,t01_8) {
//    EXPECT_EQ(CTCI().TT01_8());
//}
//#define TT01_9 isFlipedString
//TEST(CTIC,t01_9) {
//    EXPECT_EQ(true,CTCI().TT01_9("waterbottle","erbottlewat"));
//    EXPECT_EQ(false,CTCI().TT01_9("aa","aba"));
//}
