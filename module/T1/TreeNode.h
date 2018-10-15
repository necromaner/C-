#ifndef T1_TREENODE_H
#define T1_TREENODE_H

#include <iostream>
#include <vector>
using namespace std;
//内连韩式
struct TreeNode {
    int val;//值
    int height; //此节点为根的子树的高度
    int bF;//平衡因子
    TreeNode *left;//左子树
    TreeNode *right;//右子树
    TreeNode(int x) : val(x), left(NULL), right(NULL),height(0),bF(0) {}
};
//dele
//close
TreeNode* build(vector<int> x);//新建
void insert(TreeNode *&t,int x);//插入
void deleteVal(TreeNode *&t,int x);//删除

void outPut_DLR(TreeNode *t);//根左右
void outPut_LDR(TreeNode *t);//左根右
void outPut_LRD(TreeNode *t);//左右根

vector<int> DLR(TreeNode *t);
vector<int> LDR(TreeNode *t);
vector<int> LRD(TreeNode *t);



bool find(TreeNode *t,int x);//搜索
void outPut_Find(TreeNode *t,int x);//搜索

#endif //T1_TREENODE_H
