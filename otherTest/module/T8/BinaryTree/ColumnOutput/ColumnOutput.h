#ifndef T8_COLUMNOUTPUT_H
#define T8_COLUMNOUTPUT_H

#include "../BinaryTree.h"

class ColumnOutput: public BinaryTree{
private:
    map<int,vector<int>> Column_DLR(TreeNode *t,map<int, vector<int>> &x,int num);//前序遍历输出行主要函数
    map<int,vector<int>> Column_LDR(TreeNode *t,map<int, vector<int>> &x,int num);//中序遍历输出行主要函数
    map<int,vector<int>> Column_LRD(TreeNode *t,map<int, vector<int>> &x,int num);//后序遍历输出行主要函数
public:
    void outputColumn_DLR(TreeNode *t);//前序遍历输出行打印
    void outputColumn_LDR(TreeNode *t);//中序遍历输出行打印
    void outputColumn_LRD(TreeNode *t);//后序遍历输出行打印

    map<int,vector<int>> Column_DLR(TreeNode *t);//前序遍历输出行
    map<int,vector<int>> Column_LDR(TreeNode *t);//中序遍历输出行
    map<int,vector<int>> Column_LRD(TreeNode *t);//后序遍历输出行
    using BinaryTree::outPut;//父类outPut
    void outPut(map<int,vector<int>> s);//输出map<int,vector<int>>
};


#endif //T8_COLUMNOUTPUT_H
