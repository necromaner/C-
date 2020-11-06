//
// Created by necromaner on 2020/10/26.
//

#ifndef T1_REDBLACKTREE_H
#define T1_REDBLACKTREE_H

#include <iostream>
#include <stack>
#include "../list2.h"
using namespace std;
/*
红黑树具有下列五种性质：
    1.根节点黑色。
    2.每个节点为红色/黑色。
    3.红色节点下两个节点必为黑色。
    4.每一条从根至叶的路径上的黑节点数量相同。
    5.每个叶节点都是黑的。
 */
struct TreeNode {
    list_head list;                                                         //二叉树
    int val;
    bool isRed;
    TreeNode *left,*right;
    TreeNode() : val(0), isRed(true), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), isRed(true), left(nullptr), right(nullptr) {}
};
class RedBlackTree {
public:
    RedBlackTree();

    void tree_Add(int val);
    void tree_Del(int val);

private:
    TreeNode head;//链表头节点
    TreeNode *root;
    TreeNode *tree1;
    void __tree_Add(TreeNode *tree);
    void tree_Add_left(TreeNode *tree,TreeNode *add);//左子树添加
    void tree_Add_right(TreeNode *tree,TreeNode *add);//右子树添加
    void tree_Add_check(stack<TreeNode *> &st);//检查红黑树正确性
    void TreeNode_DLR(TreeNode* root);
    void TreeNode_LDR(TreeNode* root);

};


#endif //T1_REDBLACKTREE_H
