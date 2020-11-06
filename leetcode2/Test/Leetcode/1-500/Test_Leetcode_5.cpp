#include "../../Test.h"

//#define TT201
//TEST(leetcode,t201) {
//    EXPECT_EQ(,Leetcode().TT201());
//}
//#define TT202
//TEST(leetcode,t202) {
//    EXPECT_EQ(,Leetcode().TT202());
//}
//#define TT203
//TEST(leetcode,t203) {
//    EXPECT_EQ(,Leetcode().TT203());
//}
//#define TT204
//TEST(leetcode,t204) {
//    EXPECT_EQ(,Leetcode().TT204());
//}
//#define TT205
//TEST(leetcode,t205) {
//    EXPECT_EQ(,Leetcode().TT205());
//}
//#define TT206
//TEST(leetcode,t206) {
//    EXPECT_EQ(,Leetcode().TT206());
//}
//#define TT207
//TEST(leetcode,t207) {
//    EXPECT_EQ(,Leetcode().TT207());
//}
//#define TT208
//TEST(leetcode,t208) {
//    EXPECT_EQ(,Leetcode().TT208());
//}
//#define TT209
//TEST(leetcode,t209) {
//    EXPECT_EQ(,Leetcode().TT209());
//}
//#define TT210
//TEST(leetcode,t210) {
//    EXPECT_EQ(,Leetcode().TT210());
//}
//#define TT211
//TEST(leetcode,t211) {
//    EXPECT_EQ(,Leetcode().TT211());
//}
//#define TT212
//TEST(leetcode,t212) {
//    EXPECT_EQ(,Leetcode().TT212());
//}
//#define TT213
//TEST(leetcode,t213) {
//    EXPECT_EQ(,Leetcode().TT213());
//}
//#define TT214
//TEST(leetcode,t214) {
//    EXPECT_EQ(,Leetcode().TT214());
//}
//#define TT215
//TEST(leetcode,t215) {
//    EXPECT_EQ(,Leetcode().TT215());
//}
//#define TT216
//TEST(leetcode,t216) {
//    EXPECT_EQ(,Leetcode().TT216());
//}
//#define TT217
//TEST(leetcode,t217) {
//    EXPECT_EQ(,Leetcode().TT217());
//}
//#define TT218
//TEST(leetcode,t218) {
//    EXPECT_EQ(,Leetcode().TT218());
//}
//#define TT219
//TEST(leetcode,t219) {
//    EXPECT_EQ(,Leetcode().TT219());
//}
//#define TT220
//TEST(leetcode,t220) {
//    EXPECT_EQ(,Leetcode().TT220());
//}
//#define TT221
//TEST(leetcode,t221) {
//    EXPECT_EQ(,Leetcode().TT221());
//}
//#define TT222
//TEST(leetcode,t222) {
//    EXPECT_EQ(,Leetcode().TT222());
//}
//#define TT223
//TEST(leetcode,t223) {
//    EXPECT_EQ(,Leetcode().TT223());
//}
//#define TT224
//TEST(leetcode,t224) {
//    EXPECT_EQ(,Leetcode().TT224());
//}
#define TT225 MyStack1
TEST(leetcode,t225) {
    TT225* obj = new TT225();//栈（先进后出）
    obj->push(1);
    obj->push(2);
    obj->push(3);
    EXPECT_EQ(3, obj->pop());
    EXPECT_EQ(2, obj->top());
    EXPECT_EQ(false, obj->empty());
    EXPECT_EQ(2, obj->pop());
    EXPECT_EQ(1, obj->pop());
    EXPECT_EQ(0, obj->pop());
    EXPECT_EQ(0, obj->pop());
    EXPECT_EQ(true, obj->empty());
}
//#define TT226
//TEST(leetcode,t226) {
//    EXPECT_EQ(,Leetcode().TT226());
//}
//#define TT227
//TEST(leetcode,t227) {
//    EXPECT_EQ(,Leetcode().TT227());
//}
//#define TT228
//TEST(leetcode,t228) {
//    EXPECT_EQ(,Leetcode().TT228());
//}
//#define TT229
//TEST(leetcode,t229) {
//    EXPECT_EQ(,Leetcode().TT229());
//}
//#define TT230
//TEST(leetcode,t230) {
//    EXPECT_EQ(,Leetcode().TT230());
//}
//#define TT231
//TEST(leetcode,t231) {
//    EXPECT_EQ(,Leetcode().TT231());
//}
//#define TT232
//TEST(leetcode,t232) {
//    EXPECT_EQ(,Leetcode().TT232());
//}
//#define TT233
//TEST(leetcode,t233) {
//    EXPECT_EQ(,Leetcode().TT233());
//}
#define TT234 isPalindrome
TEST(leetcode,t234) {
    vector<int> head;
    head={};
    EXPECT_EQ(true,Leetcode().TT234(SetListNode(head)));
    head={1,2};
    EXPECT_EQ(false,Leetcode().TT234(SetListNode(head)));
    head={1,2,3,2,1};
    EXPECT_EQ(false,Leetcode().TT234(SetListNode(head)));
    head={1,2,3,3,1};
    EXPECT_EQ(false,Leetcode().TT234(SetListNode(head)));
    head={1,2,2,1};
    EXPECT_EQ(true,Leetcode().TT234(SetListNode(head)));
}
#define TT235 lowestCommonAncestor
TEST(leetcode,t235) {
    EXPECT_EQ("[6]",GetTreeNode(Leetcode().TT235(SetTreeNode("[6,2,8,0,4,7,9,null,null,3,5]"),SetTreeNode("2"),SetTreeNode("8"))));
    EXPECT_EQ("[2]",GetTreeNode(Leetcode().TT235(SetTreeNode("[6,2,8,0,4,7,9,null,null,3,5]"),SetTreeNode("2"),SetTreeNode("4"))));
    EXPECT_EQ("[2]",GetTreeNode(Leetcode().TT235(SetTreeNode("[6,2,8,0,4,7,9,null,null,3,5]"),SetTreeNode("4"),SetTreeNode("2"))));
}
//#define TT236
//TEST(leetcode,t236) {
//    EXPECT_EQ(,Leetcode().TT236());
//}
//#define TT237
//TEST(leetcode,t237) {
//    EXPECT_EQ(,Leetcode().TT237());
//}
//#define TT238
//TEST(leetcode,t238) {
//    EXPECT_EQ(,Leetcode().TT238());
//}
//#define TT239
//TEST(leetcode,t239) {
//    EXPECT_EQ(,Leetcode().TT239());
//}
//#define TT240
//TEST(leetcode,t240) {
//    EXPECT_EQ(,Leetcode().TT240());
//}
//#define TT241
//TEST(leetcode,t241) {
//    EXPECT_EQ(,Leetcode().TT241());
//}
//#define TT242
//TEST(leetcode,t242) {
//    EXPECT_EQ(,Leetcode().TT242());
//}
//#define TT243
//TEST(leetcode,t243) {
//    EXPECT_EQ(,Leetcode().TT243());
//}
//#define TT244
//TEST(leetcode,t244) {
//    EXPECT_EQ(,Leetcode().TT244());
//}
//#define TT245
//TEST(leetcode,t245) {
//    EXPECT_EQ(,Leetcode().TT245());
//}
//#define TT246
//TEST(leetcode,t246) {
//    EXPECT_EQ(,Leetcode().TT246());
//}
//#define TT247
//TEST(leetcode,t247) {
//    EXPECT_EQ(,Leetcode().TT247());
//}
//#define TT248
//TEST(leetcode,t248) {
//    EXPECT_EQ(,Leetcode().TT248());
//}
//#define TT249
//TEST(leetcode,t249) {
//    EXPECT_EQ(,Leetcode().TT249());
//}
//#define TT250
//TEST(leetcode,t250) {
//    EXPECT_EQ(,Leetcode().TT250());
//}
