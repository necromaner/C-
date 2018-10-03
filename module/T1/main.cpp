
#include "TreeNode.h"
/*
 * 用c/c++实现平衡二叉树，创建查找插入删除，导出排序数值。
 */

int main() {
    printf("----------------新建-----------------\n");
    vector<int> x={10,20,30,40,50,60,70,80};
    TreeNode *t=build(x);
    outPut_DLR(t);
    outPut_LDR(t);
    outPut_LRD(t);
    printf("----------------查找-----------------\n");
    outPut_Find(t,10);
    outPut_Find(t,11);
    printf("----------------添加-----------------\n");
    insert(t,90);
    outPut_DLR(t);
    insert(t,90);
    outPut_DLR(t);
    insert(t,75);
    outPut_DLR(t);
    printf("----------------删除-----------------\n");
    deleteVal(t,81);
    outPut_DLR(t);
    deleteVal(t,80);
    outPut_DLR(t);
    deleteVal(t,75);
    outPut_DLR(t);
    deleteVal(t,70);
    outPut_DLR(t);
    deleteVal(t,70);
    outPut_DLR(t);
    printf("----------------end-----------------\n");
    
    
    return 0;
}