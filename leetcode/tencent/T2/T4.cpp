#include "../Output.h"
/*
合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6


 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int j = 0; j < lists.size();) {
            if(lists[j]==NULL)
                lists.erase(lists.begin() + j);
            else
                j++;
        }
        if(lists.size()<1)
            return {};
        if(lists.size()==1)
            return lists[0];
        
        ListNode* head=new ListNode(0);
        ListNode* ptr=head;
        while (lists.size()>0){
            int ls=lists.size();
            int min=lists[0]->val;
            int num=0;
            for (int i = 0; i < ls; ++i) {
                if(min>lists[i]->val){
                    min=lists[i]->val;
                    num=i;
                }
            }
            ptr->next = new ListNode(lists[num]->val);
            ptr = ptr->next;
            lists[num]=lists[num]->next;
            if(lists[num]==NULL)
                lists.erase(lists.begin() + num);
            
        }
        return head->next;
    }
};
int main() {
    problem(__FILE__,"合并K个排序链表\n"
            "合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。");
    Solution solution;
    vector<vector<int>> s={{0,1,2},{-10,-8,-5,-4},{},{},{-3},{-10,-9,-6,-4,-3,-2,-2,-1,2},{-9,-9,-2,-1,0,1},{-9,-4,-3,-2,2,2,3,3,4}};
    vector<ListNode*> lists=inPut(s);
    outPut(0,lists);
    outPut(1,solution.mergeKLists(lists));
    return 0;
}