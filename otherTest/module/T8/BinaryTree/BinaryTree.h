//
// Created by necromaner on 2019-01-27.
//

#ifndef T8_BINARYTREE_H
#define T8_BINARYTREE_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct TreeNode {
    int val;//值
    TreeNode *left;//左子树
    TreeNode *right;//右子树
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    vector<int> DLR(TreeNode *t, vector<int> &s);//前序遍历输出主要函数
    vector<int> LDR(TreeNode *t, vector<int> &s);//中序遍历输出主要函数
    vector<int> LRD(TreeNode *t, vector<int> &s);//后序遍历输出主要函数
public:
    string outPut(vector<int> s);

    void outPut_DLR(TreeNode *t);//前序遍历打印
    void outPut_LDR(TreeNode *t);//中序遍历打印
    void outPut_LRD(TreeNode *t);//后序遍历打印

    vector<int> DLR(TreeNode *t);//前序遍历输出
    vector<int> LDR(TreeNode *t);//中序遍历输出
    vector<int> LRD(TreeNode *t);//后序遍历输出

    TreeNode *inPut_DLR_LDR(vector<int> DLR, vector<int> LDR);//前中定二叉树
    TreeNode *inPut_LDR_LRD(vector<int> LDR, vector<int> LRD);//中后定二叉树

    int findTilt(TreeNode* root);
};


#endif //T8_BINARYTREE_H
