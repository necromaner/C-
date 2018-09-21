#include "../Output.h"
/*
两数相加
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807


 */
class Solution {
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* l3;
        ListNode* l4;
        int carry = 0;
        while (l1||l2||carry){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            int x=sum % 10;
            l4->next= new ListNode(x);
            l4=l4->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return l3->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *p = l1, *q = l2, *curr = new ListNode(0);
        ListNode *dummyhead = curr;
        while (1) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->val = sum % 10;
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
            if (p || q) {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
            else {
                if (carry) {
                    curr->next = new ListNode(0);
                    curr = curr->next;
                }
                break;
            }
        }
        if (carry > 0) { curr->val = carry; }
        return dummyhead;
    }
};


int main() {
    problem(__FILE__,"两数相加\n"
            "给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。\n"
            "你可以假设除了数字 0 之外，这两个数字都不会以零开头。");
    Solution solution;
    ListNode* l1=inPut({2,4,3});
    ListNode* l2=inPut({5,6,4});
    outPut("l1",l1);
    outPut("l2",l2);
    
    outPut(1,solution.addTwoNumbers(l1,l2));
    return 0;
}