#include "TreeNode.h"
/*------------------------输出-----------------------------*/
void outPut(vector<int> s){
    int max_length=0;
    for (int k = 0; k < s.size(); ++k) {
        int max = to_string(s[k]).size();
        if (max_length < max) {
            max_length = max;
        }
    }
    printf("[");
    for (int i = 0; i < s.size(); ++i) {
        int max=to_string(s[i]).size();
        for (int k = 0; k < max_length-max; ++k) {
            printf(" ");
        }
        printf("%d",s[i]);
        if(i<s.size()-1)
            printf(",");
    }
    printf("]\n");
}
vector<int> DLR(TreeNode *t,vector<int>& s){//前序遍历
    s.push_back(t->val);
    if (t->left)
        DLR(t->left,s);
    if (t->right)
        DLR(t->right,s);
    return s;
}
void outPut_DLR(TreeNode *t) {//前序遍历输出，根左右
    printf("前序遍历：");
    vector<int> x;
    outPut(DLR(t,x));
}
vector<int> LDR(TreeNode *t,vector<int>& s){//中序遍历
    if (t->left)
        LDR(t->left,s);
    s.push_back(t->val);
    if (t->right)
        LDR(t->right,s);
    return s;
}
void outPut_LDR(TreeNode *t) {//中序遍历输出，左根右
    printf("中序遍历：");
    vector<int> x;
    outPut(LDR(t,x));
}
vector<int> LRD(TreeNode *t,vector<int>& s){//后序遍历
    if (t->left)
        LRD(t->left,s);
    if (t->right)
        LRD(t->right,s);
    s.push_back(t->val);
    return s;
}
void outPut_LRD(TreeNode *t) {//后序遍历输出，左右根
    printf("后序遍历：");
    vector<int> x;
    outPut(LRD(t,x));
}
/*---------------------------------------------------------*/

/*------------------------查找-----------------------------*/
void outPut(bool s,int x){
    if(s)
        printf("存在值%d\n",x);
    else
        printf("不存在值%d\n",x);
}
bool find(TreeNode *t,int x){
    if(x==t->val)
        return true;
    if(x<t->val&&t->left)
        find(t->left,x);
    if(x>t->val&&t->right)
        find(t->right,x);
    return false;
}
void outPut_Find(TreeNode *t,int x){
    printf("链表中");
    outPut(find(t,x),x);
}
/*---------------------------------------------------------*/

void insert_unbalanced(TreeNode *&t,int x){//插入单值
    if(t->val>x){
        if(t->left)
            insert_unbalanced(t->left,x);
        else
            t->left=new TreeNode(x);
    }
    if(t->val<x){
        if(t->right)
            insert_unbalanced(t->right,x);
        else
            t->right=new TreeNode(x);
    }
}
int height(TreeNode *t){//返回高度，更新BF
    int height=0;
    if(t->left&&t->right) {
        t->bF=t->left->height-t->right->height;
        return (t->left->height>=t->right->height)?(t->left->height+1):(t->right->height+1);
    } else if(t->left) {
        t->bF=t->left->height+1;
        return (t->left->height+1);
    } else if(t->right){
        t->bF=-(t->right->height+1);
        return (t->right->height+1);
    }
    else {
        t->bF=0;
        return height;
    }
}
void refresh(TreeNode *t){//更新高度和BF
    if(t->left){
        refresh(t->left);
    }
    if(t->right){
        refresh(t->right);
    }
    t->height=height(t);
}

void LL(TreeNode *&t){
    TreeNode *tl=t->left;
    t->left=tl->right;
    tl->right=t;
    t=tl;
    refresh(t);
}
void LR(TreeNode *&t){
    TreeNode *tl=t->left;
    TreeNode *tlr=tl->right;
    t->left=tlr->right;
    tl->right=tlr->left;
    tlr->left=tl;
    tlr->right=t;
    t=tlr;
    refresh(t);
}
void RR(TreeNode *&t){
    TreeNode *tr=t->right;
    t->right=tr->left;
    tr->left=t;
    t=tr;
    refresh(t);
}
void RL(TreeNode *&t){
    TreeNode *tr=t->right;
    TreeNode *trl=tr->left;
    t->right=trl->left;
    tr->left=trl->right;
    trl->left=t;
    trl->right=tr;
    t=trl;
    refresh(t);
}

void searchBF(TreeNode *&t){
    if(t->left){
        searchBF(t->left);
    }
    if(t->right){
        searchBF(t->right);
    }
    if(t->bF>1){
        if(t->left->bF>0){
            LL(t);
        } else if(t->left->bF<0){
            LR(t);
        }
    } else if(t->bF<-1){
        if(t->right->bF>0){
            RL(t);
        } else if(t->right->bF<0){
            RR(t);
        }
    }
//    return t;
}

void insert(TreeNode *&t,int x){
    insert_unbalanced(t,x);
    refresh(t);
    searchBF(t);
}
TreeNode* build(vector<int> x){
    int xs=x.size();
    if(xs==0)
        return NULL;
    TreeNode *t=new TreeNode(x[0]);
    for (int i = 1; i < xs; ++i) {
        insert(t,x[i]);
    }
    return t;
}
int close(TreeNode *t){
    if(t->left){
    
    } else
    return t->val+10;
}
void delete_Unbalanced(TreeNode *t,int x) {
    if(t->val==x){
        TreeNode *s;
        if(t->right==NULL)   //只有右子树，情况2
        {
            s=t;
            t=t->left;
//            free(s);
        }
//        if(t->left||t->right)
//            free(t);
        t->val=close(t);
    } else if(t->val>x){
        delete_Unbalanced(t->left,x);
    } else if(t->val<x){
        delete_Unbalanced(t->right,x);
    }
}
void deleteVal(TreeNode *&t,int x){
    delete_Unbalanced(t,x);
}