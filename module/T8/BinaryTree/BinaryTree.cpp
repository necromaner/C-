//
// Created by necromaner on 2019-01-27.
//

#include "BinaryTree.h"
string BinaryTree::outPut(vector<int> s){
    string ss;
    int max_length=0;
    for (int k = 0; k < s.size(); ++k) {
        int max = (int)to_string(s[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    ss+="[";
    for (int i = 0; i < s.size(); ++i) {
        int max=(int)to_string(s[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            ss+=" ";
        }
        ss+=to_string(s[i]);
        if(i<s.size()-1)
            ss+=",";
    }
    ss+="]";
    return ss;
}
vector<int> BinaryTree::DLR(TreeNode *t){
    vector<int> x;
    x=DLR(t,x);
    return x;
}
vector<int> BinaryTree::LDR(TreeNode *t){
    vector<int> x;
    x=LDR(t,x);
    return x;
}
vector<int> BinaryTree::LRD(TreeNode *t){
    vector<int> x;
    x=LRD(t,x);
    return x;
}

vector<int> BinaryTree::DLR(TreeNode *t,vector<int>& s){//前序遍历
    s.push_back(t->val);
    if (t->left)
        DLR(t->left,s);
    if (t->right)
        DLR(t->right,s);
    return s;
}
vector<int> BinaryTree::LDR(TreeNode *t,vector<int>& s){//中序遍历
    if (t->left)
        LDR(t->left,s);
    s.push_back(t->val);
    if (t->right)
        LDR(t->right,s);
    return s;
}
vector<int> BinaryTree::LRD(TreeNode *t,vector<int>& s){//后序遍历
    if (t->left)
        LRD(t->left,s);
    if (t->right)
        LRD(t->right,s);
    s.push_back(t->val);
    return s;
}

void BinaryTree::outPut_DLR(TreeNode *t) {//前序遍历输出，根左右
    printf("前序遍历：%s\n",outPut(DLR(t)).c_str());
}
void BinaryTree::outPut_LDR(TreeNode *t) {//中序遍历输出，左根右
    printf("中序遍历：%s\n",outPut(LDR(t)).c_str());
}
void BinaryTree::outPut_LRD(TreeNode *t) {//后序遍历输出，左右根
    printf("后序遍历：%s\n",outPut(LRD(t)).c_str());
}

TreeNode *BinaryTree::inPut_DLR_LDR(vector<int> DLR, vector<int> LDR) {
    TreeNode *t = new TreeNode(DLR[0]);
    for (int i = 0; i < LDR.size(); ++i) {
        if (DLR[0] == LDR[i]) {
            vector<int> DLR1(DLR.begin() + 1, DLR.begin() + 1 + i);
            vector<int> DLR2(DLR.begin() + 1 + i, DLR.end());
            vector<int> LDR1(LDR.begin(), LDR.begin() + i);
            vector<int> LDR2(LDR.begin() + 1 + i, LDR.end());
            if (!DLR1.empty() || !LDR1.empty())
                t->left = inPut_DLR_LDR(DLR1, LDR1);
            if (!DLR2.empty() || !LDR2.empty())
                t->right = inPut_DLR_LDR(DLR2, LDR2);
            return t;
        }
    }
    return t;
}
TreeNode *BinaryTree::inPut_LDR_LRD(vector<int> LDR, vector<int> LRD) {
    TreeNode *t = new TreeNode(LRD[LRD.size() - 1]);
    for (int i = 0; i < LDR.size(); ++i) {
        if (LRD[LRD.size() - 1] == LDR[i]) {
            vector<int> LDR1(LDR.begin(), LDR.begin() + i);//中左
            vector<int> LDR2(LDR.begin() + 1 + i, LDR.end());//中右
            vector<int> LRD1(LRD.begin(), LRD.begin() + i);//后左
            vector<int> LRD2(LRD.begin() + i, LRD.end() - 1);;//后右
            if (!LDR1.empty() || !LRD1.empty())
                t->left = inPut_LDR_LRD(LDR1, LRD1);
            if (!LDR2.empty() || !LRD2.empty())
                t->right = inPut_LDR_LRD(LDR2, LRD2);
            break;
        }
    }
    return t;
}

int BinaryTree::findTilt(TreeNode* root) {
    int answer=0;
    int left=0;
    int right=0;
    if(root->left!= nullptr){
        left=findTilt(root->left);
    }
    if(root->right!=nullptr){
        right=findTilt(root->right);
    }
    answer+=left+right+root->val;
    return answer;
}