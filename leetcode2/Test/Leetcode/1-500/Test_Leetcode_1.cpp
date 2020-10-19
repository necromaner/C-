#include "../../Test.h"

#define TT1 twoSum
TEST(leetcode,t1) {
    vector<int> nums;
    vector<int> a1;
    int target;

    nums = {2, 7, 11, 15};
    a1 = {0, 1};
    target = 9;
    EXPECT_EQ(a1, Leetcode().TT1(nums, target)) << "默认";

    nums = {0, 4, 3, 0};
    a1 = {0, 3};
    target = 0;
    EXPECT_EQ(a1, Leetcode().TT1(nums, target)) << "0值";

    nums = {-1, -2, -3, -4, -5};
    a1 = {2, 4};
    target = -8;
    EXPECT_EQ(a1, Leetcode().TT1(nums, target)) << "负值";
}
#define TT2 addTwoNumbers
TEST(leetcode,t2) {
    ListNode *l1;
    ListNode *l2;
    ListNode *l3;
    l1=SetListNode({2,4,3});
    l2=SetListNode({5,6,4});
    l3=SetListNode({7,0,8});
    EXPECT_EQ( GetListNode(l3),GetListNode(Leetcode().TT2(l1,l2))) << "默认";

    l1=SetListNode({1,3,6,3});
    l2=SetListNode({5,6,4});
    l3=SetListNode({6,9,0,4});
    EXPECT_EQ( GetListNode(l3),GetListNode(Leetcode().TT2(l1,l2))) << "默认";

    l1=SetListNode({5});
    l2=SetListNode({5});
    l3=SetListNode({0,1});
    EXPECT_EQ( GetListNode(l3),GetListNode(Leetcode().TT2(l1,l2)));

    l1=SetListNode({1});
    l2=SetListNode({9,9});
    l3=SetListNode({0,0,1});
    EXPECT_EQ( GetListNode(l3),GetListNode(Leetcode().TT2(l1,l2)));

}
#define TT3 lengthOfLongestSubstring
TEST(leetcode,t3) {
    EXPECT_EQ(3, Leetcode().TT3("abcabcbb"));
    EXPECT_EQ(2, Leetcode().TT3("aab"));
    EXPECT_EQ(1, Leetcode().TT3("bbbbb"));
    EXPECT_EQ(3, Leetcode().TT3("pwwkew"));
    EXPECT_EQ(4, Leetcode().TT3("bvdf"));
}
#define TT4 findMedianSortedArrays
TEST(leetcode,t4) {
    vector<int> nums1,nums2;
    nums1={1,3,4,9};
    nums2={1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(4,Leetcode().TT4(nums1,nums2));
}
#define TT5 longestPalindrome
TEST(leetcode,t5) {
    EXPECT_EQ("bab",Leetcode().TT5("babad"));
    EXPECT_EQ("bb",Leetcode().TT5("cbbd"));
}
#define TT6 convert
TEST(leetcode,t6) {
    EXPECT_EQ("1592468037",Leetcode().TT6("1234567890",3));
    EXPECT_EQ("1726835940",Leetcode().TT6("1234567890",4));
    EXPECT_EQ("PAHNAPLSIIGYIR",Leetcode().TT6("PAYPALISHIRING",3));
}
#define TT7 reverse
TEST(leetcode,t7) {
    EXPECT_EQ(Leetcode().TT7(123), 321) << "默认";
    EXPECT_EQ(Leetcode().TT7(-123), -321) << "负数";
    EXPECT_EQ(Leetcode().TT7(2147447412), 2147447412) << "极限正数";
    EXPECT_EQ(Leetcode().TT7(-2147447412), -2147447412) << "极限负数";
    EXPECT_EQ(Leetcode().TT7(2147457412), 0) << "极限正数";
    EXPECT_EQ(Leetcode().TT7(-2147457412), 0) << "极限负数";
}
#define TT8 myAtoi
TEST(leetcode,t8) {
    EXPECT_EQ(42,Leetcode().TT8("42"))<<"正常";
    EXPECT_EQ(-42,Leetcode().TT8("   -42"))<<"开头空格 负数";
    EXPECT_EQ(42,Leetcode().TT8("   +42"))<<"开头空格 正数";
    EXPECT_EQ(4193,Leetcode().TT8("4193 with words"))<<"后空格 字母";
    EXPECT_EQ(0,Leetcode().TT8("words and 987"))<<"前空格字母";
    EXPECT_EQ(-2147483648,Leetcode().TT8("-91283472332"))<<"极限小";
    EXPECT_EQ(-2147483647,Leetcode().TT8("-2147483647"))<<"极限边缘";
    EXPECT_EQ(2147483647,Leetcode().TT8("91283472332"))<<"极限大";
    EXPECT_EQ(42,Leetcode().TT8("42 1"))<<"后空格 数字";
    EXPECT_EQ(0,Leetcode().TT8("- 42"))<<"负数 后空格";
    EXPECT_EQ(1,Leetcode().TT8("001"))<<"0开头";
    EXPECT_EQ(-1,Leetcode().TT8("-001"))<<"0开头 负数";
    EXPECT_EQ(12345678,Leetcode().TT8("  0000000000012345678"))<<"0开头 负数";
}
#define TT9 isPalindrome
TEST(leetcode,t9) {
    EXPECT_EQ(true,Leetcode().TT9(121));
    EXPECT_EQ(true,Leetcode().TT9(0));
    EXPECT_EQ(false,Leetcode().TT9(10));
    EXPECT_EQ(false,Leetcode().TT9(-121));
    EXPECT_EQ(true,Leetcode().TT9(121));
    EXPECT_EQ(true,Leetcode().TT9(121));
}
#define TT10 isMatch
TEST(leetcode,t10) {
    EXPECT_EQ(false,Leetcode().TT10("aa","a"));
    EXPECT_EQ(true,Leetcode().TT10("aa","a*"));
    EXPECT_EQ(true,Leetcode().TT10("ab",".*"));
    EXPECT_EQ(true,Leetcode().TT10("aab","c*a*b"));
    EXPECT_EQ(false,Leetcode().TT10("mississippi","mis*is*p*."));
//    EXPECT_EQ(true,Leetcode().TT10("aa","*"));
//    EXPECT_EQ(true,Leetcode().TT10("aa","*a"));
    EXPECT_EQ(false,Leetcode().TT10("aa","a**"));
    EXPECT_EQ(true,Leetcode().TT10("a",".*a"));
}
#define TT11 maxArea
TEST(leetcode,t11) {
    vector<int> height;
    height={1,8,6,2,5,4,8,3,7};
    EXPECT_EQ(49,Leetcode().TT11(height));
}
#define TT12 intToRoman
TEST(leetcode,t12) {
    EXPECT_EQ("I",Leetcode().TT12(1));
    EXPECT_EQ("II",Leetcode().TT12(2));
    EXPECT_EQ("III",Leetcode().TT12(3));
    EXPECT_EQ("IV",Leetcode().TT12(4));
    EXPECT_EQ("V",Leetcode().TT12(5));
    EXPECT_EQ("VI",Leetcode().TT12(6));
    EXPECT_EQ("VII",Leetcode().TT12(7));
    EXPECT_EQ("VIII",Leetcode().TT12(8));
    EXPECT_EQ("IX",Leetcode().TT12(9));
    EXPECT_EQ("X",Leetcode().TT12(10));
    EXPECT_EQ("LVIII",Leetcode().TT12(58));
    EXPECT_EQ("MCMXCIV",Leetcode().TT12(1994));
}
#define TT13 romanToInt
TEST(leetcode,t13) {
    EXPECT_EQ(1,Leetcode().TT13("I"));
    EXPECT_EQ(2,Leetcode().TT13("II"));
    EXPECT_EQ(3,Leetcode().TT13("III"));
    EXPECT_EQ(4,Leetcode().TT13("IV"));
    EXPECT_EQ(5,Leetcode().TT13("V"));
    EXPECT_EQ(6,Leetcode().TT13("VI"));
    EXPECT_EQ(7,Leetcode().TT13("VII"));
    EXPECT_EQ(8,Leetcode().TT13("VIII"));
    EXPECT_EQ(9,Leetcode().TT13("IX"));
    EXPECT_EQ(10,Leetcode().TT13("X"));
    EXPECT_EQ(58,Leetcode().TT13("LVIII"));
    EXPECT_EQ(1994,Leetcode().TT13("MCMXCIV"));
}
#define TT14 longestCommonPrefix
TEST(leetcode,t14) {
    vector<string> strs;
    string answer;
    strs = {"flower", "flow", "flight"};
    answer = "fl";
    EXPECT_EQ(Leetcode().TT14(strs), answer) << "默认";
    strs = {"dog", "racecar", "car"};
    answer = "";
    EXPECT_EQ(Leetcode().TT14(strs), answer) << "无";
    strs = {"", ""};
    answer = "";
    EXPECT_EQ(Leetcode().TT14(strs), answer) << "无";
    strs = {"abc", "abc", "abc", "abc"};
    answer = "abc";
    EXPECT_EQ(Leetcode().TT14(strs), answer) << "无";
}
#define TT15 threeSum
TEST(leetcode,t15) {
    vector<int> aa;
    vector<vector<int>> ans;
    aa = {-1, 0, 1, 2, -1, -4};
    ans = {
            {-1, -1, 2},
            {-1, 0,  1}
    };
    EXPECT_EQ(ans, Leetcode().TT15(aa));
    aa = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    ans = {
            {-4, -2, 6},
            {-4, 0,  4},
            {-4, 1,  3},
            {-4, 2,  2},
            {-2, -2, 4},
            {-2, 0,  2}
    };
    EXPECT_EQ(ans, Leetcode().TT15(aa));
}
#define TT16 threeSumClosest
TEST(leetcode,t16) {
    vector<int> aa;
    aa={-1,2,1,-4};
    EXPECT_EQ(2,Leetcode().TT16(aa,1));
    aa={1,1,1,0};
    EXPECT_EQ(2,Leetcode().TT16(aa,-100));
    aa={0,2,1,-3};
    EXPECT_EQ(0,Leetcode().TT16(aa,1));
    aa={-100,-98,-2,-1};
    EXPECT_EQ(-101,Leetcode().TT16(aa,-101));
}
#define TT17 letterCombinations
TEST(leetcode,t17) {
    vector<string> ans;
    ans={"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    EXPECT_EQ(ans,Leetcode().TT17("23"));
}
#define TT18 fourSum
TEST(leetcode,t18) {
    vector<int> nums;
    vector<vector<int>> ans;
    nums = {1, 0, -1, 0, -2, 2};
    ans = {{-2, -1, 1, 2},
           {-2, 0,  0, 2},
           {-1, 0,  0, 1}};
    EXPECT_EQ(ans, Leetcode().TT18(nums, 0));
}
#define TT19 removeNthFromEnd
TEST(leetcode,t19) {
    vector<int> ans,head;
    ans={1,2,3,5};
    head={1,2,3,4,5};
    EXPECT_EQ(ans,GetListNode(Leetcode().TT19(SetListNode(head),2)));
    ans={};
    head={1};
    EXPECT_EQ(ans,GetListNode(Leetcode().TT19(SetListNode(head),1)));
    ans={1};
    head={1,2};
    EXPECT_EQ(ans,GetListNode(Leetcode().TT19(SetListNode(head),1)));
    ans={2};
    head={1,2};
    EXPECT_EQ(ans,GetListNode(Leetcode().TT19(SetListNode(head),2)));
}
#define TT20 isValid
TEST(leetcode,t20) {
    EXPECT_EQ(true,Leetcode().TT20("()"));
    EXPECT_EQ(true,Leetcode().TT20("()[]{}"));
    EXPECT_EQ(false,Leetcode().TT20("(]"));
    EXPECT_EQ(false,Leetcode().TT20("([)]"));
    EXPECT_EQ(true,Leetcode().TT20("{[]}"));
    EXPECT_EQ(true,Leetcode().TT20(""));
}
#define TT21 mergeTwoLists
TEST(leetcode,t21) {
    ListNode *l1;
    ListNode *l2;
    ListNode *ans;
    l1 = SetListNode({1, 2, 4});
    l2 = SetListNode({1, 3, 4});
    ans = SetListNode({1, 1, 2, 3, 4, 4});
    EXPECT_EQ(GetListNode(ans), GetListNode(Leetcode().TT21(l1, l2)));
    l1 = SetListNode({});
    l2 = SetListNode({0});
    ans = SetListNode({0});
    EXPECT_EQ(GetListNode(ans), GetListNode(Leetcode().TT21(l1, l2)));
    l1 = SetListNode({0});
    l2 = SetListNode({});
    ans = SetListNode({0});
    EXPECT_EQ(GetListNode(ans), GetListNode(Leetcode().TT21(l1, l2)));
}
#define TT22 generateParenthesis
TEST(leetcode,t22) {
    vector<string> ans;
    ans={"((()))",
         "(()())",
         "(())()",
         "()(())",
         "()()()"};
    EXPECT_EQ(ans,Leetcode().TT22(3));
}
//#define TT23
//TEST(leetcode,t23) {
//    EXPECT_EQ(,Leetcode().TT23());
//}
#define TT24 swapPairs
TEST(leetcode,t24) {
    ListNode *head;
    ListNode *ans;
    head = SetListNode({1, 2, 3, 4});
    ans = SetListNode({2, 1, 4, 3});
    EXPECT_EQ(GetListNode(ans), GetListNode(Leetcode().TT24(head)));
    head = SetListNode({1});
    ans = SetListNode({1});
    EXPECT_EQ(GetListNode(ans), GetListNode(Leetcode().TT24(head)));
    head = SetListNode({});
    ans = SetListNode({});
    EXPECT_EQ(GetListNode(ans), GetListNode(Leetcode().TT24(head)));
    head = SetListNode({1,2,3});
    ans = SetListNode({2,1,3});
    EXPECT_EQ(GetListNode(ans), GetListNode(Leetcode().TT24(head)));
}
//#define TT25
//TEST(leetcode,t25) {
//    EXPECT_EQ(,Leetcode().TT25());
//}
//#define TT26
//TEST(leetcode,t26) {
//    EXPECT_EQ(,Leetcode().TT26());
//}
//#define TT27
//TEST(leetcode,t27) {
//    EXPECT_EQ(,Leetcode().TT27());
//}
//#define TT28
//TEST(leetcode,t28) {
//    EXPECT_EQ(,Leetcode().TT28());
//}
//#define TT29
//TEST(leetcode,t29) {
//    EXPECT_EQ(,Leetcode().TT29());
//}
//#define TT30
//TEST(leetcode,t30) {
//    EXPECT_EQ(,Leetcode().TT30());
//}
//#define TT31
//TEST(leetcode,t31) {
//    EXPECT_EQ(,Leetcode().TT31());
//}
//#define TT32
//TEST(leetcode,t32) {
//    EXPECT_EQ(,Leetcode().TT32());
//}
//#define TT33
//TEST(leetcode,t33) {
//    EXPECT_EQ(,Leetcode().TT33());
//}
//#define TT34
//TEST(leetcode,t34) {
//    EXPECT_EQ(,Leetcode().TT34());
//}
#define TT35 searchInsert
TEST(leetcode,t35) {
    vector<int> nums;
    nums = {1, 3, 5, 6};
    EXPECT_EQ(Leetcode().TT35(nums, 5), 2);
    EXPECT_EQ(Leetcode().TT35(nums, 2), 1);
    EXPECT_EQ(Leetcode().TT35(nums, 7), 4);
    EXPECT_EQ(Leetcode().TT35(nums, 0), 0);
}
#define TT35_1 searchInsert1
TEST(leetcode,t35_1) {
    vector<int> nums;
    nums = {1, 3, 5, 6};
    EXPECT_EQ(Leetcode().TT35(nums, 5), 2);
    EXPECT_EQ(Leetcode().TT35(nums, 2), 1);
    EXPECT_EQ(Leetcode().TT35(nums, 7), 4);
    EXPECT_EQ(Leetcode().TT35(nums, 0), 0);
}
//#define TT36
//TEST(leetcode,t36) {
//    EXPECT_EQ(,Leetcode().TT36());
//}
#define TT37 solveSudoku
TEST(leetcode,t37) {
    vector<vector<char>> board={
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},

            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},

            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> answer={
            {'5','3','4','6','7','8','9','1','2'},
            {'6','7','2','1','9','5','3','4','8'},
            {'1','9','8','3','4','2','5','6','7'},
            {'8','5','9','7','6','1','4','2','3'},
            {'4','2','6','8','5','3','7','9','1'},
            {'7','1','3','9','2','4','8','5','6'},
            {'9','6','1','5','3','7','2','8','4'},
            {'2','8','7','4','1','9','6','3','5'},
            {'3','4','5','2','8','6','1','7','9'}
    };
    Leetcode().TT37(board);
    EXPECT_EQ(answer,board);
}
//#define TT38
//TEST(leetcode,t38) {
//    EXPECT_EQ(,Leetcode().TT38());
//}
//#define TT39
//TEST(leetcode,t39) {
//    EXPECT_EQ(,Leetcode().TT39());
//}
//#define TT40
//TEST(leetcode,t40) {
//    EXPECT_EQ(,Leetcode().TT40());
//}
//#define TT41
//TEST(leetcode,t41) {
//    EXPECT_EQ(,Leetcode().TT41());
//}
//#define TT42
//TEST(leetcode,t42) {
//    EXPECT_EQ(,Leetcode().TT42());
//}
//#define TT43
//TEST(leetcode,t43) {
//    EXPECT_EQ(,Leetcode().TT43());
//}
//#define TT44
//TEST(leetcode,t44) {
//    EXPECT_EQ(,Leetcode().TT44());
//}
//#define TT45
//TEST(leetcode,t45) {
//    EXPECT_EQ(,Leetcode().TT45());
//}
//#define TT46
//TEST(leetcode,t46) {
//    EXPECT_EQ(,Leetcode().TT46());
//}
//#define TT47
//TEST(leetcode,t47) {
//    EXPECT_EQ(,Leetcode().TT47());
//}
//#define TT48
//TEST(leetcode,t48) {
//    EXPECT_EQ(,Leetcode().TT48());
//}
//#define TT49
//TEST(leetcode,t49) {
//    EXPECT_EQ(,Leetcode().TT49());
//}
//#define TT50
//TEST(leetcode,t50) {
//    EXPECT_EQ(,Leetcode().TT50());
//}



