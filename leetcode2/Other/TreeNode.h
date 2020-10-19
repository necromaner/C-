//
// Created by necromaner on 2020/9/14.
//

#ifndef LEETCODE2_TREENODE_H
#define LEETCODE2_TREENODE_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode {                                                            //二叉树
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void TreeNode_DLR(TreeNode* root);//前序遍历
void TreeNode_DLR1(TreeNode* root);//前序遍历
void TreeNode_DLR2(TreeNode* root);//前序遍历
void TreeNode_DLR_Morris(TreeNode* root);//前序遍历
void TreeNode_LDR(TreeNode* root);//中序遍历
void TreeNode_LDR1(TreeNode* root);//中序遍历
void TreeNode_LDR2(TreeNode* root);//中序遍历
void TreeNode_LDR_Morris(TreeNode *head);//中序遍历
void TreeNode_LRD(TreeNode* root);//后序遍历
void TreeNode_LRD1(TreeNode* root);//后序遍历
void TreeNode_LRD2(TreeNode* root);//后序遍历
void TreeNode_LRD_Morris(TreeNode *head);//后序遍历
void TreeNode_DFS(TreeNode* root);//深度优先搜索
void TreeNode_BFS(TreeNode* root);//宽度优先搜索



TreeNode *SetTreeNode(string tree);//设置一个二叉树
string GetTreeNode(TreeNode *tree);//二叉树->string

#endif //LEETCODE2_TREENODE_H
