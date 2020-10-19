#include "../Test.h"

TEST(TreeNode,GetTreeNode) {
    TreeNode *tree0 = new TreeNode(0);
    TreeNode *tree1 = new TreeNode(1);
    TreeNode *tree2 = new TreeNode(2);
    TreeNode *tree3 = new TreeNode(3);
    TreeNode *tree4 = new TreeNode(4);
    TreeNode *tree5 = new TreeNode(5);
    TreeNode *tree6 = new TreeNode(6);
    TreeNode *tree7 = new TreeNode(7);
    TreeNode *tree8 = new TreeNode(8);
    TreeNode *tree9 = new TreeNode(9);
    TreeNode *tree10 = new TreeNode(10);
    tree0->left = tree1;
    tree0->right = tree2;

    tree1->right = tree4;

    tree4->left = tree7;
    tree4->right = tree8;
    tree7->left = tree9;
    tree7->right = tree10;
    EXPECT_EQ( GetTreeNode(tree0),"[0,1,2,null,4,null,null,7,8,9,10]");

//    EXPECT_EQ( Leetcode().GetTreeNode(tree1),"[1,2,3,4,5,6,7,8,9,10]");
}
TEST(TreeNode,SetTreeNode){
    string a;
    TreeNode *setList;
    a="[0,1,2,null,4,null,null,7,8,9,10]";
    setList = SetTreeNode(a);
    EXPECT_EQ( GetTreeNode(setList),a);
}
TEST(TreeNode,TreeNode_LDR){
    string a;
//     0
//    / \
//   1   2
//    \
//     4
//    / \
//   7   8
//  / \
// 9   10
cout<<"二叉树:"<<endl;
cout<<"        0\n"
      "      /   \\\n"
      "    1       2\n"
      "      \\\n"
      "        4\n"
      "      /   \\\n"
      "    7       8\n"
      "  /   \\\n"
      "9       10"<<endl<<endl;

    TreeNode *root;
    a="[0,1,2,null,4,null,null,7,8,9,10]";
    root = SetTreeNode(a);
    cout<<"前序遍历:"<<endl;
    cout<<"  递归实现:"<<endl;
    TreeNode_DLR(root);
    cout<<endl;
    cout<<"  迭代实现:"<<endl;
    TreeNode_DLR1(root);
    cout<<endl;
    TreeNode_DLR2(root);
    cout<<endl;
    cout<<"  Morris实现:"<<endl;
    TreeNode_DLR_Morris(root);
    cout<<endl;
    cout<<endl;

    cout<<"中序遍历:"<<endl;
    cout<<"  递归实现:"<<endl;
    TreeNode_LDR(root);
    cout<<endl;
    cout<<"  迭代实现:"<<endl;
    TreeNode_LDR1(root);
    cout<<endl;
    cout<<"  Morris实现:"<<endl;
    TreeNode_LDR_Morris(root);
    cout<<endl;
    cout<<endl;

    cout<<"后续遍历:"<<endl;
    cout<<"  递归实现:"<<endl;
    TreeNode_LRD(root);
    cout<<endl;
    cout<<"  迭代实现:"<<endl;
    TreeNode_LRD1(root);
    cout<<endl;
    cout<<"  Morris实现:"<<endl;
    TreeNode_LRD_Morris(root);
    cout<<endl;
    cout<<endl;

    cout<<"深度优先搜索:"<<endl;
    TreeNode_DFS(root);
    cout<<endl;
    cout<<endl;

    cout<<"宽度优先搜索:"<<endl;
    TreeNode_BFS(root);
    cout<<endl;
    cout<<endl;


}