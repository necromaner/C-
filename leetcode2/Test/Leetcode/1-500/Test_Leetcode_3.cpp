#include "../../Test.h"

//#define TT101 isSymmetric
//TEST(leetcode,t101) {
//    EXPECT_EQ(Leetcode().TT101(Leetcode().SetTreeNode("[1,2,2]")), true) << "相同";
//}
//#define TT102
//TEST(leetcode,t102) {
//    EXPECT_EQ(,Leetcode().TT102());
//}
//#define TT103
//TEST(leetcode,t103) {
//    EXPECT_EQ(,Leetcode().TT103());
//}
//#define TT104 maxDepth
//TEST(leetcode,t104) {
//    EXPECT_EQ(Leetcode().TT104(Leetcode().SetTreeNode("[1,2,2,4,5,6,7]")), 3) << "2";
//}
//#define TT105
//TEST(leetcode,t105) {
//    EXPECT_EQ(,Leetcode().TT105());
//}
#define TT106 buildTree
TEST(leetcode,t106) {
    vector<int> inorder;
    vector<int> postorder;
    inorder={9,3,15,20,7};
    postorder={9,15,7,20,3};
    EXPECT_EQ("[3,9,20,null,null,15,7]",GetTreeNode(Leetcode().TT106(inorder,postorder)));
}
//#define TT107
//TEST(leetcode,t107) {
//    EXPECT_EQ(,Leetcode().TT107());
//}
//#define TT108
//TEST(leetcode,t108) {
//    EXPECT_EQ(,Leetcode().TT108());
//}
//#define TT109
//TEST(leetcode,t109) {
//    EXPECT_EQ(,Leetcode().TT109());
//}
//#define TT110
//TEST(leetcode,t110) {
//    EXPECT_EQ(,Leetcode().TT110());
//}
//#define TT111
//TEST(leetcode,t111) {
//    EXPECT_EQ(,Leetcode().TT111());
//}
//#define TT112
//TEST(leetcode,t112) {
//    EXPECT_EQ(,Leetcode().TT112());
//}
#define TT113 pathSum
TEST(leetcode,t113) {
    vector<vector<int>> aa={{5,4,11,2},{5,8,4,5}};
    EXPECT_EQ(aa,Leetcode().TT113(SetTreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]"),22));
}
//#define TT114
//TEST(leetcode,t114) {
//    EXPECT_EQ(,Leetcode().TT114());
//}
//#define TT115
//TEST(leetcode,t115) {
//    EXPECT_EQ(,Leetcode().TT115());
//}
#define TT116 connect_116
TEST(leetcode,t116) {
    EXPECT_EQ("[0,#,1,2,#,3,4,5,6,#]",GetNode(Leetcode().TT116(SetNode("[0,1,2,3,4,5,6]"))));
    EXPECT_EQ("[]",GetNode(Leetcode().TT116(SetNode("[]"))));
}
#define TT117 connect
TEST(leetcode,t117) {
    EXPECT_EQ("[0,#,1,2,#,4,#,7,8,#,9,10,#]",GetNode(Leetcode().TT117(SetNode("[0,1,2,null,4,null,null,7,8,9,10]"))));
}
//#define TT118
//TEST(leetcode,t118) {
//    EXPECT_EQ(,Leetcode().TT118());
//}
//#define TT119
//TEST(leetcode,t119) {
//    EXPECT_EQ(,Leetcode().TT119());
//}
//#define TT120
//TEST(leetcode,t120) {
//    EXPECT_EQ(,Leetcode().TT120());
//}
//#define TT121
//TEST(leetcode,t121) {
//    EXPECT_EQ(,Leetcode().TT121());
//}
//#define TT122
//TEST(leetcode,t122) {
//    EXPECT_EQ(,Leetcode().TT122());
//}
//#define TT123
//TEST(leetcode,t123) {
//    EXPECT_EQ(,Leetcode().TT123());
//}
//#define TT124
//TEST(leetcode,t124) {
//    EXPECT_EQ(,Leetcode().TT124());
//}
//#define TT125
//TEST(leetcode,t125) {
//    EXPECT_EQ(,Leetcode().TT125());
//}
//#define TT126
//TEST(leetcode,t126) {
//    EXPECT_EQ(,Leetcode().TT126());
//}
//#define TT127
//TEST(leetcode,t127) {
//    EXPECT_EQ(,Leetcode().TT127());
//}
//#define TT128
//TEST(leetcode,t128) {
//    EXPECT_EQ(,Leetcode().TT128());
//}
//#define TT129
//TEST(leetcode,t129) {
//    EXPECT_EQ(,Leetcode().TT129());
//}
//#define TT130
//TEST(leetcode,t130) {
//    EXPECT_EQ(,Leetcode().TT130());
//}
//#define TT131
//TEST(leetcode,t131) {
//    EXPECT_EQ(,Leetcode().TT131());
//}
//#define TT132
//TEST(leetcode,t132) {
//    EXPECT_EQ(,Leetcode().TT132());
//}
//#define TT133
//TEST(leetcode,t133) {
//    EXPECT_EQ(,Leetcode().TT133());
//}
//#define TT134
//TEST(leetcode,t134) {
//    EXPECT_EQ(,Leetcode().TT134());
//}
//#define TT135
//TEST(leetcode,t135) {
//    EXPECT_EQ(,Leetcode().TT135());
//}
//#define TT136
//TEST(leetcode,t136) {
//    EXPECT_EQ(,Leetcode().TT136());
//}
//#define TT137
//TEST(leetcode,t137) {
//    EXPECT_EQ(,Leetcode().TT137());
//}
//#define TT138
//TEST(leetcode,t138) {
//    EXPECT_EQ(,Leetcode().TT138());
//}
//#define TT139
//TEST(leetcode,t139) {
//    EXPECT_EQ(,Leetcode().TT139());
//}
//#define TT140
//TEST(leetcode,t140) {
//    EXPECT_EQ(,Leetcode().TT140());
//}
#define TT141 hasCycle
TEST(leetcode,t141) {
    ListNode *l1=new ListNode(3);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(0);
    ListNode *l4=new ListNode(-4);
    ListNode *l5=new ListNode(-4);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l2;
    EXPECT_EQ(true,Leetcode().TT141(l1));
    l4->next=l5;
    EXPECT_EQ(false,Leetcode().TT141(l1));
    l1->next=l1;
    EXPECT_EQ(true,Leetcode().TT141(l1));
    EXPECT_EQ(false,Leetcode().TT141(nullptr));
}
#define TT142 detectCycle
TEST(leetcode,t142) {
    ListNode *l1=new ListNode(3);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(0);
    ListNode *l4=new ListNode(-4);
    ListNode *l5=new ListNode(-4);
    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=l2;
    EXPECT_EQ(l2,Leetcode().TT142(l1));
    l4->next=l5;
    EXPECT_EQ(nullptr,Leetcode().TT142(l1));
    l1->next=l1;
    EXPECT_EQ(l1,Leetcode().TT142(l1));
    EXPECT_EQ(nullptr,Leetcode().TT142(nullptr));
}
//#define TT143
//TEST(leetcode,t143) {
//    EXPECT_EQ(,Leetcode().TT143());
//}
//#define TT144
//TEST(leetcode,t144) {
//    EXPECT_EQ(,Leetcode().TT144());
//}
//#define TT145
//TEST(leetcode,t145) {
//    EXPECT_EQ(,Leetcode().TT145());
//}
//#define TT146
//TEST(leetcode,t146) {
//    EXPECT_EQ(,Leetcode().TT146());
//}
//#define TT147
//TEST(leetcode,t147) {
//    EXPECT_EQ(,Leetcode().TT147());
//}
//#define TT148
//TEST(leetcode,t148) {
//    EXPECT_EQ(,Leetcode().TT148());
//}
//#define TT149
//TEST(leetcode,t149) {
//    EXPECT_EQ(,Leetcode().TT149());
//}
//#define TT150
//TEST(leetcode,t150) {
//    EXPECT_EQ(,Leetcode().TT150());
//}