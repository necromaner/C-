#include "../Output.h"
/*
旋转链表
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL


 */
class Solution {
public:
    /*
     * 1.尾节点指向头节点
     * 2.循环找到需求头节点
     * 3.头节点前指向NULL
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode* ptr=head;
        while (ptr){
            if(ptr->next==NULL){
                ptr->next=head;
                break;
            }
            ptr=ptr->next;
        }
        ptr=ptr->next;
        for (int i = 0; i < k; ++i) {
            head=head->next;
            ptr=ptr->next;
            if(i==k-1){
                outPut(ptr->val);
                outPut(ptr->next->val);
                ptr->next=NULL;
                ptr==NULL;
                
            }
        }
        return head;
    }
};
int main() {
    problem(__FILE__,"旋转链表\n"
            "给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。");
    Solution solution;
    vector<int> num={1,2,3,4,5};
    ListNode* head=inPut(num);
    int k=2;
    outPut(0,head);
    outPut(0,k);
    
    outPut(1,solution.rotateRight(head,k));
    return 0;
}