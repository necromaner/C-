#include "../Output.h"
/*
环形链表
给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？

 */
class Solution {
public:
    bool hasCycle1(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *p = head;
        while (head->next != NULL) {
            head = head->next;
            if (p == head)
                return true;
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        ListNode* pfast = head;
        ListNode* pslow = head;
        do{
            if(pfast!=NULL)
                pfast=pfast->next;
            if(pfast!=NULL)
                pfast=pfast->next;
            if(pfast==NULL)
                return false;
            pslow = pslow->next;
        }while(pfast != pslow);
        return true;
    }
};
int main() {
    problem(__FILE__,"环形链表\n"
            "给定一个链表，判断链表中是否有环。");
    Solution solution;
    vector<int> x={3,2,0,-4};
    ListNode* head=inPut(1,x);
//    outPut(0,head);
    
    outPut(1,solution.hasCycle(head));
    return 0;
}