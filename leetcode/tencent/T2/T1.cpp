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
    ListNode* reverseList1(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;//处理最小输入的情况，即空链表和单节点链表
        ListNode* second = head->next;//将即将被调用的下一个节点分离，即将下一个调用的输入存在second里
        ListNode* reverseHead = reverseList1(second);//将调用后的结果存储，这个结果就是最终结果。之后利用递归，调用刚才存好的输入
        second->next = head;//上面一步的调用已经完成以second为首的链表的反转，所以现在second变成了反转完成后的尾节点
                            //把这个尾节点的next指向一开始输入的前驱，即head，完成整个链表反转
        head->next = NULL;//最开始的头节点要变成尾节点，即在后面补null使链表终结
        return reverseHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode *p=NULL;//当前
        ListNode *q ;//下一个
        while (head){
            q=head->next;
            head->next=p;
            p=head;
            head=q;
        }
        return p;
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