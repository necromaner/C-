#include "../Output.h"
/*
反转链表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return NULL;
    }
};
int main() {
    problem(__FILE__,"反转链表\n"
            "反转一个单链表。");
    Solution solution;
    ListNode *p7=inPut({1,2,3,4,5});
    outPut(0,p7);
    outPut(1,solution.reverseList(p7));
    return 0;
}