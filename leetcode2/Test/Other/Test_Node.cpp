#include "../Test.h"
TEST(Node,GetNode) {
    Node *tree0 = new Node(0);
    Node *tree1 = new Node(1);
    Node *tree2 = new Node(2);
    Node *tree3 = new Node(3);
    Node *tree4 = new Node(4);
    Node *tree5 = new Node(5);
    Node *tree6 = new Node(6);
    Node *tree7 = new Node(7);
    Node *tree8 = new Node(8);
    Node *tree9 = new Node(9);
    Node *tree10 = new Node(10);
    tree0->left = tree1;
    tree0->right = tree2;

    tree1->right = tree4;
    tree1->next=tree2;

    tree4->left = tree7;
    tree4->right = tree8;
    tree7->left = tree9;
    tree7->right = tree10;
    tree7->next=tree8;
    tree9->next=tree10;
    EXPECT_EQ( GetNode(tree0),"[0,#,1,2,#,4,#,7,8,#,9,10,#]");
}
TEST(Node,SetNode){
    string a;
    Node *setList;
    a="[0,1,2,null,4,null,null,7,8,9,10]";
    setList = SetNode(a);
    EXPECT_EQ( GetNode(setList),"[0,#,1,2,#,4,#,7,8,#,9,10,#]");
}
TEST(ListNode,ListNode1){
    vector<int> list;
    ListNode *setList;
    list={1,2,3,4};
    setList = SetListNode(list);
    EXPECT_EQ(list, GetListNode(setList));
    list.clear();

    list={1};
    setList = SetListNode(list);
    EXPECT_EQ(list, GetListNode(setList));

    list={};
    setList = SetListNode(list);
    EXPECT_EQ(list, GetListNode(setList));
}