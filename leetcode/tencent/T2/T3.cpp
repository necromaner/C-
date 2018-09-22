#include "../Output.h"
/*
合并两个有序链表
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4


 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        while (l1 || l2) {
            if(l1==NULL){
                ptr->next = new ListNode(l2->val);
                l2 = l2->next;
            } else if(l2==NULL){
                ptr->next = new ListNode(l1->val);
                l1 = l1->next;
            } else{
                if (l1->val <= l2->val) {
                    ptr->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    ptr->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
            ptr = ptr->next;
        }
        return head->next;
    }
};
int main() {
    problem(__FILE__,"合并两个有序链表\n"
            "将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。");
    Solution solution;
    
    ListNode* l1=inPut({1,3,5});
    ListNode* l2=inPut({2,4,6});
    outPut("l1",l1);
    outPut("l2",l2);
    
    outPut(1,solution.mergeTwoLists(l1,l2));
    outPut("l1",l1);
    outPut("l2",l2);
    return 0;
}