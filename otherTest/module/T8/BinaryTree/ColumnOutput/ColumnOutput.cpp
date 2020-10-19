#include "ColumnOutput.h"

void ColumnOutput::outputColumn_DLR(TreeNode *t) {
    outPut(Column_DLR(t));
}
void ColumnOutput::outputColumn_LDR(TreeNode *t) {
    outPut(Column_LDR(t));
}
void ColumnOutput::outputColumn_LRD(TreeNode *t) {
    outPut(Column_LRD(t));
}
map<int, vector<int>> ColumnOutput::Column_DLR(TreeNode *t) {
    map<int, vector<int>> x;
    return Column_DLR(t,x,0);
}
map<int, vector<int>> ColumnOutput::Column_LDR(TreeNode *t) {
    map<int, vector<int>> x;
    return Column_LDR(t,x,0);
}
map<int, vector<int>> ColumnOutput::Column_LRD(TreeNode *t) {
    map<int, vector<int>> x;
    return Column_LRD(t,x,0);
}


map<int, vector<int>> ColumnOutput::Column_DLR(TreeNode *t, map<int, vector<int>> &x,int num) {
    if (x.count(num))//存在key
        x[num].push_back(t->val);
    else//不存在key
        x[num] = {t->val};
    if (t->left)
        Column_DLR(t->left, x,num - 1);
    if (t->right)
        Column_DLR(t->right,x, num + 1);
    return x;
}
map<int, vector<int>> ColumnOutput::Column_LDR(TreeNode *t,map<int, vector<int>> &x,int num) {
    if (t->left)
        Column_LDR(t->left, x,num - 1);
    if (x.count(num))//存在key
        x[num].push_back(t->val);
    else             //不存在key
        x[num] = {t->val};
    if (t->right)
        Column_LDR(t->right, x,num + 1);
    return x;
}
map<int, vector<int>> ColumnOutput::Column_LRD(TreeNode *t,map<int, vector<int>> &x,int num) {
    if (t->left)
        Column_LRD(t->left,x, num - 1);
    if (t->right)
        Column_LRD(t->right,x, num + 1);
    if (x.count(num))//存在key
        x[num].push_back(t->val);
    else             //不存在key
        x[num] = {t->val};
    return x;
}
void ColumnOutput::outPut(map<int, vector<int>> s) {
    for(auto x:s)
        printf("key:%3d  value:%s\n", x.first, outPut(x.second).c_str());
}
