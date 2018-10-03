
#include "ListNode.h"
/*
 * 优先级链表
 */

int main() {
    printf("---------------新建-----------------\n");
    vector<int> x={6,3,2,6,7,3,4};
    ListNode* l=build(x);
    outPut(l);
    printf("---------------添加-----------------\n");
    insert(l,1);
    outPut(l);
    insert(l,9);
    outPut(l);
    insert(l,3);
    outPut(l);
    printf("---------------删除-----------------\n");
    close(l,1);
    outPut(l);
    close(l,9);
    outPut(l);
    close(l,3);
    outPut(l);
    close(l,33);
    outPut(l);
    printf("---------------清空-----------------\n");
    closeAll(l);
    outPut(l);
    
    printf("---------------end-----------------\n");
    return 0;
}