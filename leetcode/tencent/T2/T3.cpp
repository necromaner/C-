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
        ListNode* l3=l1;
        ListNode* l4=l3;
        while (l1||l2){
            if(l1&&l2){
                if(l1->val>l2->val){
                
                }
            }
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            printf("%d---%d\n",x,y);
            l1=l1->next;
            l2=l2->next;
        }
        return l3;
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
    return 0;
}