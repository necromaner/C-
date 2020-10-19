#include "../../Test.h"

//#define TT1001
//TEST(leetcode,t1001) {
// EXPECT_EQ(,Leetcode().TT1001());
//}
#define TT1002 commonChars
TEST(leetcode,t1002) {
    vector<string> A;
    vector<string> ans;
    A={"bella","label","roller"};
    ans={"e","l","l"};
    EXPECT_EQ(ans,Leetcode().TT1002(A));
    A={"cool","lock","cook"};
    ans={"c","o"};
    EXPECT_EQ(ans,Leetcode().TT1002(A));
    A={"bella","","roller"};
    ans={};
    EXPECT_EQ(ans,Leetcode().TT1002(A));
}
//#define TT1003
//TEST(leetcode,t1003) {
// EXPECT_EQ(,Leetcode().TT1003());
//}
//#define TT1004
//TEST(leetcode,t1004) {
// EXPECT_EQ(,Leetcode().TT1004());
//}
//#define TT1005
//TEST(leetcode,t1005) {
// EXPECT_EQ(,Leetcode().TT1005());
//}
//#define TT1006
//TEST(leetcode,t1006) {
// EXPECT_EQ(,Leetcode().TT1006());
//}
//#define TT1007
//TEST(leetcode,t1007) {
// EXPECT_EQ(,Leetcode().TT1007());
//}
//#define TT1008
//TEST(leetcode,t1008) {
// EXPECT_EQ(,Leetcode().TT1008());
//}
//#define TT1009
//TEST(leetcode,t1009) {
// EXPECT_EQ(,Leetcode().TT1009());
//}
//#define TT1010
//TEST(leetcode,t1010) {
// EXPECT_EQ(,Leetcode().TT1010());
//}
//#define TT1011
//TEST(leetcode,t1011) {
// EXPECT_EQ(,Leetcode().TT1011());
//}
//#define TT1012
//TEST(leetcode,t1012) {
// EXPECT_EQ(,Leetcode().TT1012());
//}
//#define TT1013
//TEST(leetcode,t1013) {
// EXPECT_EQ(,Leetcode().TT1013());
//}
//#define TT1014
//TEST(leetcode,t1014) {
// EXPECT_EQ(,Leetcode().TT1014());
//}
//#define TT1015
//TEST(leetcode,t1015) {
// EXPECT_EQ(,Leetcode().TT1015());
//}
//#define TT1016
//TEST(leetcode,t1016) {
// EXPECT_EQ(,Leetcode().TT1016());
//}
//#define TT1017
//TEST(leetcode,t1017) {
// EXPECT_EQ(,Leetcode().TT1017());
//}
//#define TT1018
//TEST(leetcode,t1018) {
// EXPECT_EQ(,Leetcode().TT1018());
//}
//#define TT1019
//TEST(leetcode,t1019) {
// EXPECT_EQ(,Leetcode().TT1019());
//}
//#define TT1020
//TEST(leetcode,t1020) {
// EXPECT_EQ(,Leetcode().TT1020());
//}
//#define TT1021
//TEST(leetcode,t1021) {
// EXPECT_EQ(,Leetcode().TT1021());
//}
//#define TT1022
//TEST(leetcode,t1022) {
// EXPECT_EQ(,Leetcode().TT1022());
//}
//#define TT1023
//TEST(leetcode,t1023) {
// EXPECT_EQ(,Leetcode().TT1023());
//}
//#define TT1024
//TEST(leetcode,t1024) {
// EXPECT_EQ(,Leetcode().TT1024());
//}
#define TT1025 divisorGame
TEST(leetcode,t1025) {
    EXPECT_EQ(Leetcode().TT1025(2), true) << "默认";
    EXPECT_EQ(Leetcode().TT1025(3), false) << "默认";
}
//#define TT1026
//TEST(leetcode,t1026) {
// EXPECT_EQ(,Leetcode().TT1026());
//}
//#define TT1027
//TEST(leetcode,t1027) {
// EXPECT_EQ(,Leetcode().TT1027());
//}
//#define TT1028
//TEST(leetcode,t1028) {
// EXPECT_EQ(,Leetcode().TT1028());
//}
//#define TT1029
//TEST(leetcode,t1029) {
// EXPECT_EQ(,Leetcode().TT1029());
//}
//#define TT1030
//TEST(leetcode,t1030) {
// EXPECT_EQ(,Leetcode().TT1030());
//}
//#define TT1031
//TEST(leetcode,t1031) {
// EXPECT_EQ(,Leetcode().TT1031());
//}
//#define TT1032
//TEST(leetcode,t1032) {
// EXPECT_EQ(,Leetcode().TT1032());
//}
//#define TT1033
//TEST(leetcode,t1033) {
// EXPECT_EQ(,Leetcode().TT1033());
//}
//#define TT1034
//TEST(leetcode,t1034) {
// EXPECT_EQ(,Leetcode().TT1034());
//}
//#define TT1035
//TEST(leetcode,t1035) {
// EXPECT_EQ(,Leetcode().TT1035());
//}
//#define TT1036
//TEST(leetcode,t1036) {
// EXPECT_EQ(,Leetcode().TT1036());
//}
//#define TT1037
//TEST(leetcode,t1037) {
// EXPECT_EQ(,Leetcode().TT1037());
//}
//#define TT1038
//TEST(leetcode,t1038) {
// EXPECT_EQ(,Leetcode().TT1038());
//}
//#define TT1039
//TEST(leetcode,t1039) {
// EXPECT_EQ(,Leetcode().TT1039());
//}
//#define TT1040
//TEST(leetcode,t1040) {
// EXPECT_EQ(,Leetcode().TT1040());
//}
//#define TT1041
//TEST(leetcode,t1041) {
// EXPECT_EQ(,Leetcode().TT1041());
//}
//#define TT1042
//TEST(leetcode,t1042) {
// EXPECT_EQ(,Leetcode().TT1042());
//}
//#define TT1043
//TEST(leetcode,t1043) {
// EXPECT_EQ(,Leetcode().TT1043());
//}
//#define TT1044
//TEST(leetcode,t1044) {
// EXPECT_EQ(,Leetcode().TT1044());
//}
//#define TT1045
//TEST(leetcode,t1045) {
// EXPECT_EQ(,Leetcode().TT1045());
//}
//#define TT1046
//TEST(leetcode,t1046) {
// EXPECT_EQ(,Leetcode().TT1046());
//}
//#define TT1047
//TEST(leetcode,t1047) {
// EXPECT_EQ(,Leetcode().TT1047());
//}
//#define TT1048
//TEST(leetcode,t1048) {
// EXPECT_EQ(,Leetcode().TT1048());
//}
//#define TT1049
//TEST(leetcode,t1049) {
// EXPECT_EQ(,Leetcode().TT1049());
//}
//#define TT1050
//TEST(leetcode,t1050) {
// EXPECT_EQ(,Leetcode().TT1050());
//}